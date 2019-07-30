/* CS261- Assignment 1 - Q.1*/
/* Name: Anthony Huynh
* Date: 1/13/2019
* Solution description: allocates memory for 10 students and assigns a random unique id between 1 and 10
	and a random score between 0 and 100, then calculates minimum, maximum, and average score. 
	Will deallocate memory at end
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


const int numberStudents = 10;

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	struct student* studentList = malloc(numberStudents * sizeof(struct student));

	/*Return the pointer*/
	return studentList;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void generate(struct student* students) {
	/*Generate random and unique IDs and random scores for ten students,
	IDs being between 1 and 10, scores between 0 and 100*/
	
	//to generate unique and random id, will set an array to hold ints 1-10 and then shuffle array
	int array[10];
	for (int i = 0; i < numberStudents; i++)
	{
		array[i] = i + 1;
	}

	//Fisher-Yates shuffle obtained from
	//https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
	// Start from the last element and swap one by one. We don't 
	// need to run for the first element that's why i > 0 
	for (int i = numberStudents - 1; i > 0; i--)
	{
		// Pick a random index from 0 to i 
		int j = rand() % (i + 1);

		// Swap arr[i] with the element at random index 
		swap(&array[i], &array[j]);
	}
	
	for (int i = 0; i < numberStudents; i++)
	{
		students[i].id = array[i];
		students[i].score = rand() % 101;
	}

}



void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/
	for (int i = 0; i < numberStudents; i++)
	{
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the
	ten students*/
	int minScore = students[0].score;
	int maxScore = students[0].score;
	double averageScore = students[0].score;

	for (int i = 1; i < numberStudents; i++)
	{
		//replaces min if new score is less than current min score
		if (students[i].score < minScore)
		{
			minScore = students[i].score;
		}
		//replaces max if new score is greater than current max score
		if (students[i].score > maxScore)
		{
			maxScore = students[i].score;
		}
		//adds new score to average
		averageScore = averageScore + students[i].score;
	}

	averageScore = averageScore / (double)numberStudents;

	printf("Min Score: %d\n", minScore);
	printf("Max Score: %d\n", maxScore);
	printf("Average score: %f\n", averageScore);

}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	free(stud);
}

int main() {
	struct student* stud = NULL;
	srand(time(NULL));

	/*Call allocate*/
	stud = allocate();
	if (stud == 0)
	{
		return 0;
	}

	/*Call generate*/
	generate(stud);

	/*Call output*/
	output(stud);

	/*Call summary*/
	summary(stud);

	/*Call deallocate*/
	if (stud != 0)
	{
		deallocate(stud);
	}

	return 0;
}

