/* CS261- Assignment 1 - Q.2*/
/* Name: Anthony Huynh
* Date: 1/14/2019
* Solution description: This program generates a random integer for x, y , and z. Then calls foo using a pointer to x,
	pointer to y, and z. Foo swaps the addresses locally and returns the value of z decremented by 1.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) {
	/*Swap the addresses stored in the pointer variables a and b*/
	int* temp;

	temp = a;
	a = b;
	b = temp;

	/*Decrement the value of integer variable c*/
	c = c - 1;

	/*Return c*/
	return c;
}

int main() {
	/*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	srand(time(NULL));
	int x = rand() % 11;
	int y = rand() % 11;
	int z = rand() % 11;

	/*Print the values of x, y and z*/
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("z: %d\n", z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	foo(&x, &y, z);

	/*Print the values of x, y and z*/
	printf("x after calling foo: %d\n", x);
	printf("y after calling foo: %d\n", y);
	printf("z after calling foo: %d\n", z);

	/*Print the value returned by foo*/
	printf("value returned from foo: %d\n", foo(&x, &y, z));

	//A. The return value is different from z. This is because z is passed by value and so any changes to c within foo
	//	do not affect z.
	//B. No, x and y are the same after calling foo. This is because the addresses are changed inside foo, but that change 
	//	is local and thus will not reflect outside of foo.

	return 0;
}




