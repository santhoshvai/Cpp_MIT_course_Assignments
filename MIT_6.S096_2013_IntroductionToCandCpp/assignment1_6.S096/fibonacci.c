#include <stdio.h>
#include "fibonacci.h"

void print_fib(int n) {
	printf("%d\n", fib(n));
}

int fib(int n) {
	if (n < 2) return n;
	int firstFib = 0;
	int secondFib = 1;
	int currentFib = 0;
	int i;
	for(i=2; i<=n; i++) {
		currentFib = firstFib + secondFib;
		firstFib = secondFib;
		secondFib = currentFib;
	}
	return currentFib;
}
