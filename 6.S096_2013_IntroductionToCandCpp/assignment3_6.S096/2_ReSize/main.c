#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* The purpose of resize.c is to create an initial array of a user-specified size, then dynamically resize the array to a new user-specified size. I've given a shell of the code, including code to get user-specified sizes as ints.

However, the code is missing a few things. You must manage the memory for the array! Look at the comments in the code that describe what should be done and fill in blanks. Make sure the program compiles and runs as expected. */

int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1*sizeof(int))/* Fill in*/;
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		*(a1+i)=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ",*(a1+i)/*Fill in*/ );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = realloc(a1,n2*sizeof(int))/* Fill in*/;

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	for(i=n1; i<n2; i++){
		//Set each value in a1 to 100
		*(a1+i)=0;
		
	}


	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",*(a1+i));
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
