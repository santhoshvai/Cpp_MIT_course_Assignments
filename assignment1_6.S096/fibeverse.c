#include <stdlib.h>
#include <string.h>
#include "fibonacci.h"
#include "reverse.h"

int main(int argc, char *argv[]) {
	int i = 1;

#ifdef FIBONACCI
	if (i < argc) {
		print_fib(atoi(argv[i])); //atoi converts from string to integer
		i++;
	}
#endif	

#ifdef REVERSE
	if (i < argc) {
		reverse(argv[i], strlen(argv[i]));
		i++;
	}
#endif
	return 0;
}
