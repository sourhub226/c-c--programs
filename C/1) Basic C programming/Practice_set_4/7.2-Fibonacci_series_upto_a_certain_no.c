//to find fibonacci series upto a certain no.
#include <stdio.h>

int main()
{
	int n,a=1,b=0,i,c=0;
	printf("Enter the last no: ");
	scanf("%d",&n);
	printf("\nFibonacci series upto %d:\n",n);
	
	while(c<=n)
	{
		printf("%d\t",c);
		c=a+b;
		a=b;
		b=c;
	}
	getch();
}
