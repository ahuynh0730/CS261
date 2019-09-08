# Assignment 2

## Part 1: Implementation of Dynamic Array, Stack, and Bag
First, complete the Worksheets 14 (Dynamic Array), 15 (Dynamic Array Amortized Execution Time Analysis), 16 (Dynamic Array Stack),
and 21 (Dynamic Array Bag). These worksheets will get you started on the implementations, but you will NOT turn them in.

Next, complete the dynamic array and the dynamic array-based implementation of a stack and a bag in dynamicArray.c. The
comments for each function will help you understand what each function should do.

We have provided the header file for this assignment, DO NOT change the provided header file (dynArray.h) for this part.

You can test your implementation by using the code in testDynArray.c. This file contains several test cases for the functions in
dynamicArray.c. Try to get all the test cases to pass. You should also write more test cases on your own, but do not submit testDynArray.c.

## Part 2: Amortized Analysis of the Dynamic Array (written)
Consider the push() operation for a Dynamic Array Stack. In the best case, the operation is O(1). This corresponds to the case where there was
room in the space we have already allocated for the array. However, in the worst case, this operation slows down to O(n). This corresponds to
the case where the allocated space was full and we must copy each element of the array into a new (larger) array. This problem is designed to
discover runtime bounds on the average case when various array expansion strategies are used, but first some information on how to perform
an amortized analysis is necessary.
	
	1. Each time an item is added to the array without requiring reallocation, count 1 unit of cost. This cost will cover the assignment which actually puts the item in the array.
	2. Each time an item is added and requires reallocation, count X + 1 units of cost, where X is the number of items currently in the array.
This cost will cover the X assignments which are necessary to copy the contents of the full array into a new (larger) array, and the
additional assignment to put the item which did not fit originally.
To make this more concrete, if the array has 8 spaces and is holding 5 items, adding the sixth will cost 1. However, if the array has 8 spaces
and is holding 8 items, adding the ninth will cost 9 (8 to move the existing items + 1 to assign the ninth item once space is available).

When we can bound an average cost of an operation in this fashion, but not bound the worst case execution time, we call it amortized
constant execution time, or average execution time. Amortized constant execution time is often written as O(1)+, the plus sign indicating it
is not a guaranteed execution time bound.

In a file called amortizedAnalysis.txt, please provide answers to the following questions:

	1. How many cost units are spent in the entire process of performing 50 consecutive push operations on an empty array which starts out at capacity 8, assuming that the array will double in capacity each time a new item is added to an already full dynamic array? As N (ie. the number of pushes) grows large, under this strategy for resizing, what is the average big-oh complexity for a push?
	2. How many cost units are spent in the entire process of performing 50 consecutive push operations on an empty array which starts out at capacity 8, assuming that the array will grow by a constant 2 spaces each time a new item is added to an already full dynamic array? As N (ie. the number of pushes) grows large, under this strategy for resizing, what is the average big-oh complexity for a push?
	
## Part 3: Application of the Stack - Checking balanced parenthesis, braces, and brackets
