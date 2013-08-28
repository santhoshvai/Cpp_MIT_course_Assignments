Lab 3 Exercise
==========================

The primary goal of this lab period is to introduce pointers, addresses, arrays, and manual memory management.

**Exercise 1**
```c++
#include <stdio.h>

void square(int num) {
	num = num * num;
}

int main() {
	int x = 4;
	square(x);
	printf("%d\n", x);
	return 0;
}
```
Take a look at the above code. In lecture, I pointed out that function variables are passed by value, not reference. So this program will currently print out 4. Compile the code to confirm this.

Use pointers and addresses to modify the code so x is passed by reference instead and is squared. This will involve changes to the square function that does not involve changing void to int and giving square a return statement. Make sure your code compiles with -Wall flag without warnings.

**Exercise 2**

While coding up this exercise, listening to Hakuna Matata, I was so worry-free I forgot how to use C!

Fix the following code so that it creates a string str and copies "hakuna matata!" into it.
```c++
#include <stdio.h>

void main() {
	char str[];
	???(, "hakuna matata!"); // this line should copy "hakuna matata!"
	 // into our char array
	printf("%s\n", str);
	// Anything else?
}
```
After confirming your fix works, change the code to use heap memory instead of the stack. Remember, everything you malloc you must also free!
