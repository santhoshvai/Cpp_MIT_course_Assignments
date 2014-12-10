Lab 2 Exercise
==========================

The primary goal of this lab period is to make sure you know all of the basics of writing code in C and to avoid common pitfalls unique to C and C++.

Exercise 1
Starting with an empty .c file, write a C program to calculate the first 100 triangular numbers (0, 1, 3, 6, 10, 15, 21, …). You may check back at previous example code and slides if you get stuck, but take this an opportunity to try to recall, from memory, the standard boilerplate code you'll be writing often when starting a new C program, like the proper #include statements to be able to print to the console.

Exercise 2
Find and fix the variable shadowing bug in the following C program, which is intended to calculate the factorial function:

```c++
#include <stdio.h>

int factorial (int n) {
	int i = 1;
	while (n > 1) {
		i = i * n;
		int n = n - 1;
	}
	return i;
}

int main (int argc, char *argv[]) {
	int fac4 = factorial(4);
	int fac5 = factorial(5);
	printf("4! = %d, 5! = %d\n", fac4, fac5);
	return 0;
}
```