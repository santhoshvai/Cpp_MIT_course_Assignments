#include <stdio.h>
#include "square.h"

int main() {
	int x = 4;
	squareByVal(x);
	printf("squareByVal : %d\n", x);
	squareByRef(&x);
	printf("squareByRef : %d\n", x);
	return 0;
}