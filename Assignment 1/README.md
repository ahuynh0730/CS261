# Assignment 1 - C Programming Practice

## Q0.c
Write a program (Q0.c) to do the following:

	1. In the main() function, declare an integer, x. Then assign it to a random integer value in the interval [0, 10]. Then print the value and address(using the address of operator) of x.
	2. In fooA(int * iptr) function, print the value of the integer pointed to by iptr and the address pointed to by iptr. Change the value of the integerpointed to by iptr as instructed in the skeleton code. Print the address of iptr itself at the end.
	3. In the main() function, following the call to fooA(..), print the value of x. Answer the following question in a comment right after printing the value of x: Is the value of x different than the value that was printed at first? Why or why not?
	4. In fooB(int * jptr) function, print the value of the integer pointed to by jptr and the address pointed to by jptr. Then change the address pointed to by jptr as instructed in the skeleton code. Print the address of jptr itself at the end.
	5. In the main function, following the call to fooB(..), print the value and address of x. Answer the following question in a comment right after printing thevalue and address of x: 
		Are the value and address of x different than the value and address that were printed before the call to fooB(..)? Why or why not?


## Q1.c
Write a program (Q1.c) in which you consider the following structure:
	
	struct student{
		int score; int id;
	};
	
and the declaration in the main function:

	struct student *st = 0;
Implement the following functions and demonstrate their functionality by calling them (in the order given) from the main function --

	1.Write a function struct student* allocate () that allocates memory for ten students and returns the pointer.
	2.Write a function void generate (struct student* students) that generates random IDs and scores for each of the ten students and stores themin the array of students. Ensure that IDs are unique also and between 1 and 10 (both inclusive) and scores are between 0 and 100 (bothinclusive). To generate unique IDs you can either use the brute-force random/check/repeat (generate a random integer between 1- 10 and thenconfirm that it hasn't been used yet for a student ID) or you can use the Fisher Yates shuffle -(https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle).
	3.Write a function void output (struct student* students) that prints the IDs and scores of all the students. The output of the function needs notto be sorted.
	4.Write a function void summary (struct student* students) that prints the minimum score, maximum score and average score of the tenstudents.
	5.Write a function void deallocate (struct student* stud) that frees the memory allocated to students. Check that students is not NULL (NULL== 0) before you attempt to free it.

## Q2.c
Write a program (Q2.c) with the following:

	1)The function int foo(int *a, int *b, int c) should perform the following computations –
	- Swap the addresses of variables pointed to by the pointer variables a and b (not the values of the integers pointed to by a and b).
	- Decrement the value of c. 
	- Return the value of c.
	2)In the main function, declare three integers x, y, and z, and assign them random integer values in the interval [0, 10].
	3) Print the values of the integers x, y, and z. Call foo(..) appropriately passing x, y, and z as arguments. Print out the values of integers x, y, and z after calling the function foo(..). Also, print the value returned by foo(..).
	4)Answer the following questions in a comment at the bottom of the file:
		a)Is the return value different than the value of integer z? Why or why not?
		b) Are the values of integers x and y different before and after calling the function foo(..)? Why or why not?
		
## Q3.c 
Write a function void camelCase(char* word) where the argument "word" to the function camelCase(..) consists of at least two groups of lowercase alphabetic characters, not necessarily forming actual words in the dictionary, separated by underscores, such as “ran_dom_word” or "this_is_my_first_programming_assignment". The function camelCase(..) should remove underscores from the string and rewrite it in lower camel case (several words joined together where the first letter of the entire string is lowercase, but subsequent first letters are uppercase). Watch out for the end of the string, which is denoted by ‘\0’. It’s possible that a user provided input string may contain uppercase alphabetic characters, numeric characters, special symbols, whitespace etc. as well. You should accept such an input string too. For convenience, convert the string into a valid form before you use it for the function camelCase(..). Below are some conversion examples of what you should implement -

	a) "_random_ _word_provided" should be converted to "random_word_provided" first, then finally to "randomWordProvided" using the function camelCase(..).
	b) "@$ptr*4con_" should be converted to "ptr_con" first, then finally to "ptrCon" using the function camelCase(..).
	c) " ran dom word" should be converted to "ran_dom_word" first, then finally to "ranDomWord" using the function camelCase(..).
	d) "example word " should be converted to "example_word" first, then finally to "exampleWord" using the function camelCase(..).
	e) "ANOTHER_Word" should be converted to "another_word" first, then finally to "anotherWord" using the function camelCase(..).
	f) One or more combinations from options a, b, c, d and e should be also taken care of.
Examples of the strings that you must not allow as inputs are - "__", "_ _ _", " ", "435%7_$$", "random". Print “invalid input string” for such cases. 

You are allowed to limit the size of the input string you will provide. Finally, do not use the library functions isupper(..), islower(..) or strlen(..). Write the code on your own to perform such string operations if required.
