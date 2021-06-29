//To find factorial of a no.
#include <stdio.h>
#include <conio.h>

void main()
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

