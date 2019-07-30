/*
* CS 261 Data Structures
* Assignment 5
* Name: Anthony Huynh
* Date: 3/11/19
*/

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
const int numberSuggestions = 5;

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
	assert(file != NULL);
	assert(map != NULL);
	char* word = nextWord(file);
	while (word != NULL) {
		hashMapPut(map, word, 0);
		free(word);
		word = nextWord(file);
	}
}


/**
* will return 1 if input is valid. will return 0 if there are any non letters in string
* 
* @param string
* @return Allocated string or NULL.
*/
int isValidInput(char* input) {

	for (unsigned int i = 0; i < strlen(input); i++) {
		if (input[i] < 'a' || input[i] >'z' || input[i] == ' ') {
			return 0;
		}
	}

	return 1;
}


/**
* Returns the Levenshtein distance between two words
* Code from: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
* @param s1 and s2, two strings to compare
* @return an int containing the Levenshtein distance.
*/
int levenshtein(char *s1, char *s2) {
	unsigned int s1len, s2len, x, y, lastdiag, olddiag;
	s1len = strlen(s1);
	s2len = strlen(s2);
	unsigned int column[25];
	for (y = 1; y <= s1len; y++)
		column[y] = y;
	for (x = 1; x <= s2len; x++) {
		column[0] = x;
		for (y = 1, lastdiag = x - 1; y <= s1len; y++) {
			olddiag = column[y];
			column[y] = MIN3(column[y] + 1, column[y - 1] + 1, lastdiag + (s1[y - 1] == s2[x - 1] ? 0 : 1));
			lastdiag = olddiag;
		}
	}
	return(column[s1len]);
}

/**
* Returns the location where the new word should be inserted
* @param suggestion list and the hash link for the new word to be inserted in the list
* @return an int representing where in the list to put new word, -1 if should not be added
*/
int locationToPutNewWord(struct HashLink** suggestionList, struct HashLink* newWord) {
	for (int i = 0; i < numberSuggestions; i++) {
		if (suggestionList[i]->value == 0 || newWord->value < suggestionList[i]->value) {
			return i;
		}
	}
	return -1;
}

/**
* Starts copying each hash link to the one below it
* @param suggestion list and where to start shifting down
* @return void
*/
void moveDown(struct HashLink** suggestionList, int positionToStartShiftingDown) {
	for (int i = 4; i > positionToStartShiftingDown; i--) {
		suggestionList[i]->value = suggestionList[i - 1]->value;
		suggestionList[i]->key = suggestionList[i - 1]->key;
	}

}



/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
	assert(file != NULL);
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%[^\t\n]", inputBuffer);
		char ch = getchar();

		//loop to make sure all letters are lower case and input is valid
		for (unsigned int i = 0; i < strlen(inputBuffer); i++) {
			inputBuffer[i] = tolower(inputBuffer[i]);
		}

		while (!isValidInput(inputBuffer))
		{
			printf("Invalid input. Please enter another word or \"quit\" to quit: ");
			scanf("%[^\t\n]", inputBuffer);
			ch = getchar();
		}

        // Implement the spell checker code here..

        
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }

		if (!quit)
		{
			//if word is found in table, will tell user that the word is spelled correctly
			if (hashMapContainsKey(map, inputBuffer)) {
				printf("The inputted word %s is spelled correctly.\n", inputBuffer);
			}

			//if not in table, will calculate levenshtein distance of every word and keep an updated list of closest 5
			else {
				printf("The inputted word %s is spelled incorrectly. Here are up to 5 suggested spellings:\n", inputBuffer);
				
				//allocates an array large enough to hold the number of suggestions to be given
				struct HashLink** suggestionList = malloc(numberSuggestions * sizeof(struct HashLink*));
				assert(suggestionList != NULL);
				for (int i = 0; i < numberSuggestions; i++) {
					suggestionList[i] = malloc(sizeof(struct HashLink));
					assert(suggestionList[i] != NULL);
					suggestionList[i]->value = 0;
					suggestionList[i]->key = "za";
				}

				//to cycle through each bucket
				for (int i = 0; i < hashMapCapacity(map); i++) {
					struct HashLink* currentLink = map->table[i];
					while (currentLink != NULL) {
						//updates value with levenshtein difference between word and dictionary and input
						hashMapPut(map, currentLink->key, levenshtein(inputBuffer, currentLink->key));

						//calulates where to put new word in list
						int positionToInsert = locationToPutNewWord(suggestionList, currentLink);

						//will place word in list if position was not -1
						if (positionToInsert != -1) {

							//will down items down if value was not default value
							if (suggestionList[positionToInsert]->value != 0) {
								moveDown(suggestionList, positionToInsert);
							}

							//replaces value/key with the correct word's value/key
							suggestionList[positionToInsert]->value = currentLink->value;
							suggestionList[positionToInsert]->key = currentLink->key;

						
						}
						currentLink = currentLink->next;
					}
				}

				//prints 5 suggestions
				for (int i = 0; i < numberSuggestions; i++) {
					printf("%d. %s\n", i + 1, suggestionList[i]->key);
				}

				for (int i = 0; i < numberSuggestions; i++) {
					free(suggestionList[i]);
				}
				free(suggestionList);
			
			}
		}
	}
    
    hashMapDelete(map);
    return 0;
}