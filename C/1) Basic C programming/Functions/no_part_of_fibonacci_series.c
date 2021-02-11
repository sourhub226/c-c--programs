// To check if a no is part of fibonacci series or not
#include <stdio.h>
int fibo(int);
int main()
{
	int n,b=1;
	printf("Enter the no. to be checked: ");
	scanf ("%d",&n);
	b=fibo(n);
	if(b==0)
		printf("%d belongs to Fibonacci series",n);
	else if (b==1)
		printf("%d does not belong to Fibonacci series",n);
}

int fibo(int n)
{
	int a=1,b=0,c=0,i=1;
	while(i>0)
	{
		c=a+b;
		a=b;
		b=c;
		if(n==c)
		{
			return 0;
			break;
		}
		else if (c>n)
		{
			return 1;
			break;
		}
		i++;
	}
}
