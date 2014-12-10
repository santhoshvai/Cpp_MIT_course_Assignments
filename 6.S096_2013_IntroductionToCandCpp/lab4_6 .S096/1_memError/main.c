#include <stdlib.h>
#include <stdio.h>
 
void fn()
{
	int* x = malloc(10 * sizeof(int));
	for(int i=0; i<10; ++i) { x[i] = 0;} //was unitialised
	printf("%d",*x);
	x[9] = 0; // was setting at x[10]
	free(x); // free it!! 
}
 
int main()
{
	fn();
	return 0;
}
