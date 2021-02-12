// To find nth term of fibonacci series
#include <stdio.h>

void main()
{
	int num,a=1,b=0,i,c=0;
	printf("Enter the nth term: ");
	scanf("%d",&num);

	for(i=1;i<=num-1;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("\nnth term of Fibonacci series is %d",c);
	getch();
}
