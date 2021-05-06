// To check is a number is divisible by 2
#include <stdio.h>
#include <conio.h>

void main()
{
	int a;
	printf("Enter the number:");
	scanf("%d",&a);
	printf("\n");
	if(a%2==0)
	{
		printf("The number is a multiple of 2");
	}
	else
	{
		printf("The number is not a multiple of 2");
	}
	getch();
}
