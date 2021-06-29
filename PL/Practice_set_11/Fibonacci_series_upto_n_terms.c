// To find fibonacci series upto n terms
#include <stdio.h>

void main()
{
	int num,a=1,b=0,i,c=0;
	printf("Enter the nth term: ");
	scanf("%d",&num);
	printf("\nFibonacci series upto %d terms\n",num);
	
	for(i=1;i<=num;i++)
	{
		printf("%d\t",c);
		c=a+b;
		a=b;
		b=c;
	}
	getch();
}
