#include <stdio.h>
#include "amaze.h"
void amazeWOW(){ //for
	int i;
	printf("amaze7:\t");
	for (i = 0; i <= 10; i++) {
		if (i % 2 == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}
void amaze1(){  //while
	int i=0;
	printf("amaze1:\t");
	while(i <= 10) {
		if (i % 2 == 1) {
			printf("%d ", i);
		}
		i++;
	}
	printf("\n");
}

void amaze2(){ //do_while
	int i=0;
	printf("amaze2:\t");
	do {
		if (i % 2 == 1) {
			printf("%d ", i);
		}
		i++;
	}while(i <= 10);
	printf("\n");
}

void amaze3(){ //switch
	int i=0;
	printf("amaze3:\t");
	for (i = 0; i <= 10; i++) {		
			printf("%s ", swi(i));
			}
	printf("\n");
}
void amaze4(){ //goto
	int i=1;
	printf("amaze4:\t");
	start:
	if (i % 2 == 1) {
			printf("%d ", i);
		}
	if(i>9){ goto end;}
	else {i++; goto start;}
	end:
	printf("\n");
}
void amaze5(){ //while switch
	int i=0;
	printf("amaze5:\t");
	while(i <= 10) {	
			printf("%s ", swi(i));i++;
			}
	printf("\n");
}
void amaze6(){ //do_while switch
	int i=0;
	printf("amaze6:\t");
	do{		
			printf("%s ", swi(i));i++;
			}while(i <= 10);
	printf("\n");
}

char* swi(int i){
	switch(i){
	  case 1:
	    return "1"; break;
	  case 3:
	    return "3"; break;
	  case 5:
	    return "5"; break;
	  case 7:
	    return "7"; break;
	  case 9:
	    return "9"; break;
	  default:
	    return "";break;
	}
}