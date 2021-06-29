//to find the factorial of the no.
#include <stdio.h>

int main()
{
	int a,n,i,fact=1;
	printf("Enter the number:");
	scanf("%d",&a);
	
	for(i=1;i<=a;i++)
	{
		fact=fact*i;
	}
	printf("\n%d!=%d",a,fact);
	getch();
}

