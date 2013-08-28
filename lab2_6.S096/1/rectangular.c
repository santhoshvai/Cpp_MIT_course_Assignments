#include <stdio.h>

void rect(int n) {
for(int i=0;i<=n;++i){
int rect = (i*(i+1))/2;
printf("%d  ", rect);
}
}
