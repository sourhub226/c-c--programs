// To check if a no. is +ve or -ve
#include <stdio.h>
#include <conio.h>

void main()
{
	int a;
	printf("Enter the number:");
	scanf("%d",&a);
	
	if(a>0)
	{
		printf("\nThe number is positive");
	}
	else if(a<0)
	{
		printf("\nThe number is negative");
	}
	else
	{
		printf("\nThe number is zero");
	}
	
	getch();
}

