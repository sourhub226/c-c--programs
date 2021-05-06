// To find fibonacci series upto a certain no.
#include <stdio.h>

void main()
{
	int num,a=1,b=0,i,c=0;
	printf("Enter the last no: ");
	scanf("%d",&num);
	printf("\nFibonacci series upto %d:\n",num);
	
	while(c<=num)
	{
		printf("%d\t",c);
		c=a+b;
		a=b;
		b=c;
	}
	getch();
}
