//nth term of fibonacci
#include <stdio.h>

int fib (int n)
{
	if(n==0||n==1)
		return n;
	else
		return (fib(n-1)+fib(n-2));
}
int main()
{
	int n,ans;
	printf("Enter the nth no: ");
	scanf("%d",&n);
	ans=fib(n-1);
	printf("%dth term of Fibonacci series is %d",n,ans);
}

