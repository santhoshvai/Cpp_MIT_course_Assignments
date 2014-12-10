
#include <stdio.h>	

template <class typeParam>
typeParam max(typeParam a, typeParam b){
return (a > b ? a : b);
}
int main(){
int a = 3, b = 7;
float c = 5.5, d = 1.5;
printf("%4d\n", max(a, b)); // 7
printf("%.1f\n", max(c, d)); // 5.5
}
