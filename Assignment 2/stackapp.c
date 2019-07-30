/* CS261- Assignment 1 - Q.2*/
/* Name: Anthony Huynh
* Date: 1/22/2019
* Solution description: This program tests to make sure an equation input is balanced using a stack.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
param: 	s pointer to a string

*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s + i);
	if (c == '\0')
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
param: 	s pointer to a string
pre:
post:
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	printf("Please enter an equation to determine if it is balanced. ");
	scanf("%40[^\n]", s);

	DynArr *stack;
	stack = newDynArr(2);
	char newChar = nextChar(s);
	while (newChar != '\0')
	{
		if (newChar == '(')
		{
			pushDynArr(stack, ')');
		}
		
		else if (newChar == '{')
		{
			pushDynArr(stack, '}');
		}

		else if (newChar == '[')
		{
			pushDynArr(stack, ']');
		}

		else if (newChar == ')' || newChar == '}' || newChar == ']')
		{
			if (newChar == topDynArr(stack))
			{
				popDynArr(stack);
			}
		}
		newChar = nextChar(s);
	}

	if (isEmptyDynArr(stack))
	{
		deleteDynArr(stack);
		return 1;
	}
	else
	{
		deleteDynArr(stack);
		return 0;
	}
}

int main(int argc, char* argv[]) {

	char* s = argv[40];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);

	return 0;
}

