#include <stdio.h>

int main(int argc, char ** argv){
/*  for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    } */
	int i=1;
	start:
	printf("%s\n", argv[i]);
	if(i == argc-1){
	goto end;
	}
	else{
	i++;
	goto start;
	}
	end:
    return 0;
}
