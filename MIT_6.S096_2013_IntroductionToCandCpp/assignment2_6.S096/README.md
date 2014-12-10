Assignment 2
==========================

**Lecture Notes**

[Lecture 2: Core C (PDF)](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s096-introduction-to-c-and-c-january-iap-2013/lectures-and-assignments/core-c-control-structures-variables-scope-and-uninitialized-memory/MIT6_S096_IAP13_lec2.pdf)

**Problem 1**

Rewrite the program below, replacing the for loop with a combination of goto and if statements. The output of the program should stay the same. That is, the program should print out the arguments passed to it on the command line.
```C++
#include <stdio.h>

int main(int argc, char ** argv){
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}
```
If you ran the program like this: ./prog one two three, it would print

one
two
three

**Problem 2**

In lecture, we covered a variety of control structures for looping, such as for, while, do/while, goto, and several for testing conditions, such as if and switch.

Your task is to find seven different ways to print the odd numbers between 0 and 10 on a single line. You should give them names like amaze1, amaze2, etc. Here's a bonus amaze (that you can use as one of your seven if you like):
```C++
void amazeWOW() {
	int i;
	printf("amazeWOW:\t");
	for (i = 0; i <= 10; i++) {
		if (i % 2 == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}
```
You may need to get a little creative!

Put all of your functions in the same C file and call them in order from the main() function. We should be able to compile your program with this command and see no errors:

`gcc -Wall -std=c99 -o amaze amaze.c`

**Solutions**

Solutions are not available for this assignment.

