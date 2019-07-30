/* CS261- Assignment 1 - Q.3*/
/* Name: Anthony Huynh
* Date: 1/16/2019
* Solution description: This program will create the camel case version of a string.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define MAX_CHARS 40

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch) {
	/*Convert ch to upper case, assuming it is in lower case currently*/
	return ch - 32;
}

char toLowerCase(char ch) {
	/*Convert ch to lower case, assuming it is in upper case currently*/
	return ch + 32;
}

int stringLength(char s[]) {
	/*Return the length of the string*/
	int count = 0;
	for (int i = 0; i < MAX_CHARS; i++)
	{
		if (s[i] == '\0')
		{
			break;
		}
		else
		{
			count = count + 1;
		}
	}
	
	return count;
}

//function that will essentially remove a character at a position
void removeCharacter(char* oldString, int positionRemoved)
{
	//will make the character to be removed equal to the next character and loops through for the whole string
	for (int i = positionRemoved; i < stringLength(oldString); i++)
	{
		oldString[i] = oldString[i + 1];
	}
}

void camelCase(char* word) {
	/*Convert to camelCase*/
	for (int i = 0; i < stringLength(word); i++)
	{
		if (word[i] == '_')
		{
			word[i + 1] = toUpperCase(word[i + 1]);
			removeCharacter(word, i);
		}
	}


}

int main() {

	/*Read the string from the keyboard*/
	
	char userInput[MAX_CHARS];
	int hasLetterBeforeUnderscore = 0;
	int hasLetterAfterUnderscore = 0;
	int firstGroupPosition = 0;
	int underScorePosition = 0;
	int secondGroupPosition = 0;


	printf("Please enter a string to be converted to camel case.\n");
	scanf("%40[^\n]", userInput);

	//changes to special character to underscore
	for (int i = 0; i < stringLength(userInput) - 1; i++)
	{
		if ((userInput[i] < 65 || (userInput[i] > 90 && userInput[i] < 97) || userInput[i] > 122))
		{
			userInput[i] = '_';
		}
	}


	//loop to get rid of all underscores before first character
	while (userInput[0] == '_')
	{
		removeCharacter(userInput, 0);
	}


	//loop to make sure no consecutive underscore
	for (int i = 0; i < stringLength(userInput); i++)
	{
		while (userInput[i] == '_' && userInput[i + 1] == '_')
		{
			removeCharacter(userInput, i);
		}
	}

	//removes any underscores at end
	if (userInput[stringLength(userInput) - 1] == '_')
	{
		removeCharacter(userInput, stringLength(userInput) - 1);
	}

	//loop to make sure all characters are lower case
	for (int i = 0; i < stringLength(userInput); i++)
	{
		if (userInput[i] > 64 && userInput[i] < 91)
		{
			userInput[i] = toLowerCase(userInput[i]);
		}
	}

	//loop to find first group of letters
	for (int i = 0; i < stringLength(userInput); i++)
	{
		if (userInput[i] > 96 && userInput[i] < 123)
		{
			firstGroupPosition = i;
			break;
		}
	}

	//loop to find underscore after first group of letters
	for (int i = firstGroupPosition; i < stringLength(userInput); i++)
	{
		if (userInput[i] == '_')
		{
			underScorePosition = i;
			break;
		}
	}

	//loop to find second group of letters after underscore
	for (int i = underScorePosition; i < stringLength(userInput); i++)
	{
		if (userInput[i] > 96 && userInput[i] < 123)
		{
			secondGroupPosition = i;
			break;
		}
	}

	if (secondGroupPosition == 0)
	{
		printf("Invalid input string.\n");
		return 0;
	}

	/*Call camelCase*/
	camelCase(userInput);

	/*Print the new string*/
	printf("New string is: %s\n", userInput);


	return 0;
}

