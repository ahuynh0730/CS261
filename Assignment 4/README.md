# Assignment 4: Binary Search Trees
## PROGRAMMING
For this assignment, you will implement a binary search tree that can store any arbitrary struct in its nodes. You will start by completing the recursive implementation of the binary search tree (BST) in Worksheet 29. You will then modify it to so it can store arbitrary structures at each node, provided you have a an implementation of a compare and print_type function for that structure.

We are providing you with the following files:

	bst.c - This is the file in which you'll finish implementing the unfinished BSTree implementation. There is a main function in this file that you should modify to exercise your BST. The file contains several test cases such as testAddNode, testContainsBSTree, testLeftMost, testRemoveLeftMost, and testRemoveNode. Your implementation must pass all these test cases, and you are strongly encouraged to add your own tests as well.
	bst.h - This file should not be changed.
	structs.h - This file can be extended to test your code with different data types.
	compare.c- Put your compare and print functions in here.
	makefile.txt - Remember to rename this file to makefile (without the .txt extension).
Worksheet 29 will get you started on your implementation. However, there is one function not mentioned in the worksheet. You will be using the compare function to test two values of a node to determine if one is less than, greater than, or equal to the other. This function is similar to the compareTo function in the Comparable interface in Java. Rather than embedding it into the data structure, as you would do in Java, we will declare it and assume that the user has provided an implementation of compare in the file compare.c. That way, the user can substitute an appropriate compare function for any data type that they plan to store in the tree.

For example, if you want to store doubles in your tree, you might define the following struct to store at each node.

	struct data {
			double num;
	}
	
And then define your compare function to simply compare the two structs based on the num field. However, a user of your data structure could also do the following:

	struct pizza {
		double cost;
		int numToppings;
		char *name;
	}

And define a compare function that compares pizzas based on their name, cost, or number of toppings.

In this assignment, the TYPE macro is set to void*. This means that the type of value stored in a node is a void pointer, which means it can be a "pointer to anything". Whenever you dereference a void pointer, you must cast it to a specific type. For example, you can cast a void pointer to struct data* (see the definition in structs.h), then dereference it to get the struct data value the pointer points to. It is the programmer's responsibility to ensure that they cast the void pointer to the same type of value that was actually stored at that location. You should read up on void pointers in your C reference or on the internet.

The compare function is needed because we need some way to compare the values stored in the tree nodes. Note that we can't just compare the pointers with the >, <, or == operations since this would just compare the memory addresses the pointers point to. Instead, we want to compare some field of the struct that the pointer points to (e.g. val->number < otherVal->number). The compare function will make changing this function for different structs much easier.
