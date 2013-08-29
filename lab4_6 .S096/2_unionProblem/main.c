#include <stdio.h>
#include <string.h>

union {
    int integer;
    unsigned char byte[sizeof(int)];
} fourByteint;
//Use a union to print the individual bytes of an int. (Hint: Recall the size of ints and other data types.)

int main() {
     printf ("Enter an integer: ");
     scanf ("%d",&fourByteint.integer);
	 printf ("\nThe four bytes are : \t%d\t%d\t%d\t%d\n ",fourByteint.byte[3],fourByteint.byte[2],
	        fourByteint.byte[1],fourByteint.byte[0]);
	printf ("The integer: %d\n",fourByteint.integer);
	return 0;
}
