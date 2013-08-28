#include <stdio.h>
#include "factorial.h"

int main(int argc, char *argv[]) {	
	int fac4 = factorial(4);
	int fac5 = factorial(5);
	printf("4! = %d, 5! = %d\n", fac4, fac5);
	return 0;
}
