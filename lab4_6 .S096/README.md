Lab 4 Exercises
==========================

The primary goal of this lab period is to introduce debugging tools, and use of unions/structs.

**Exercise 1**
Download and install Valgrind on your system, if it's not already. To test if you have Valgrind, run valgrind --version. It should print the version of Valgrind that is installed.
```c++
#include <stdlib.h>
#include <stdio.h>
 
void fn()
{
	int* x = malloc(10 * sizeof(int));
	printf("%d",*x);
	x[10] = 0;
}
 
int main()
{
	fn();
	return 0;
}
```
There are 3 sources of memory errors in this code. Run valgrind to determine what they are (although I suspect you can probably tell from the code anyways).

**Exercise 2**
Use a union to print the individual bytes of an int. (Hint: Recall the size of ints and other data types.)

**Exercise 3**
Determine how much memory is required for each of the structs below. How much of that memory is padding between the members?
```c++
struct X
{
	short s; 
	int i; 
	char c;
};

struct Y
{
	int i;
	char c;
	short s;
};

struct Z
{
	int   i;
	short s;
	char  c;
};
```
