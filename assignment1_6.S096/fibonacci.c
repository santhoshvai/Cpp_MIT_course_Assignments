#include <stdio.h>
#include "fibonacci.h"
void print_fib(int n) {
	printf("%d\n", fib(n));
}

int fib(int n) {
	int dp[n+1];
	dp[0]=0;dp[1]=1;
	for(i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
