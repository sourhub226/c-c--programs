//to find first n terms of fibonacci series
#include <stdio.h>

int main()
{
	int n,a=1,b=0,i,c=0;
	printf("Enter the nth term: ");
	scanf("%d",&n);
	printf("\nFibonacci series upto %d terms\n",n);
	
	for(i=1;i<=n;i++)
	{
		printf("%d\t",c);
		c=a+b;
		a=b;
		b=c;
	}
	getch();
}
