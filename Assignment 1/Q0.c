/* CS261- Assignment 1 - Q. 0*/
/* Name: Anthony Huynh
* Date: 1/13/2019
* Solution description: This program helps show how pointers work in C.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr) {

	/*Print the value and address of the integer pointed to by iptr*/
	printf("Value of the integer pointed to by iptr: %d\n", *iptr);
	printf("Address of the integer pointed to by iptr: %p\n", iptr);

	/*Increment the value of the integer pointed to by iptr by 5*/
	*iptr = *iptr + 5;


	/*Print the address of iptr itself*/
	printf("Address of iptr: %p\n", &iptr);


	/*Dummy variable, ignore the warning*/
	int c = 5;
}


void fooB(int* jptr) {

	/*Print the value and address of the integer pointed to by jptr*/
	printf("Value of the integer pointed to by jptr: %d\n", *jptr);
	printf("Address of the integer pointed to by jptr: %p\n", jptr);

	/*Decrement the address by 1 pointed to by jptr using jptr */
	jptr = jptr - 1;

	/*Print the address of jptr itself*/
	printf("Address of jptr: %p\n", &jptr);
}


int main() {
	srand(time(NULL));

	/*Declare an integer x and initialize it randomly to a value in [0,10]
	*/
	int x = rand() % 11;

	/*Print the value and address of x*/
	printf("x: %d\n", x);
	printf("Address of x: %p\n", &x);
	
	/*Call fooA() with the address of x*/
	fooA(&x);

	/*Print the value of x*/
	printf("x: %d\n", x);

	//x is different from when x was first printed because the address of x was passed to fooA
	//which simulates passing by reference

	/*Call fooB() with the address of x*/
	fooB(&x);

	/*Print the value and address of x*/
	printf("x: %d\n", x);
	printf("Address of x: %p\n", &x);

	//The value and address of x do not change. This is because fooB changes what jptr points to, but does
	//not alter the address or value of x.


	return 0;
}


