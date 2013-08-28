#include <stdlib.h>
#include <string.h>
#include "fibonacci.h"
#include "reverse.h"

int main(int argc, char *argv[]) {
	int i = 1;

	if (i < argc) {
		print_fib(atoi(argv[i]));
		i++;
	}

	if (i < argc) {
		reverse(argv[i], strlen(argv[i]));
		i++;
	}

	return 0;
}
