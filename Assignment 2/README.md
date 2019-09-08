# Assignment 2

## Application of the Stack - Checking balanced parenthesis, braces, and brackets

Note - For this exercise you need to first make the following change in dynArray.h: Change #define TYPE int to #define TYPE char

As discussed in the lecture notes, stacks are a very commonly used abstract data type. Applications of stacks include implementation of reverse Polish notation expression evaluation and undo buffers. Stacks can also be used to check whether an expression has balanced parentheses, braces, and brackets (,{,[ or not. For example, expressions with balanced parentheses are " (x + y )", "{x + (y + z)}" and with unbalanced are "(x+y", "[x + (y+ z])". Your program should accept the inputs via command line arguments only and handle spaces in the command line input. Don't forget to wrap an input in quotes to enter it as one string. Also, make sure you handle a NULL input string. You can either consider a NULL string as balanced or ensure that the input string cannot be empty.

For this part of the assignment, you are to write a function that solves this problem using a stack(no counter integers or string functions are allowed). 
