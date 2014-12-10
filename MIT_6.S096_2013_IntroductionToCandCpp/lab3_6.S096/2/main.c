#include <stdio.h>
#include <string.h>

int main() {
	char str[17]; //add array size
	strcpy(str, "hakuna matata!"); // this line should copy "hakuna matata!"
	                         // into our char array
							 // use strcpy function
	printf("%s\n", str);
	// Anything else?
	return 0;
}
