//nth term of fibonacci
#include <stdio.h>

int fib (int n)
{
	if(n==0||n==1)
		return n;
	return (fib(n-1)+fib(n-2));
}
int main()
{
	int n,i,k;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("First %d terms of Fibonacci series:\n",n);
	for(i=0;i<n;i++)
	{
		k=fib(i);
		printf("%d\t",k);
	}
}

