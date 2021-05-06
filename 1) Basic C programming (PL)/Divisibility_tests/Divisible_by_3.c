// To check is a number is divisible by 3
#include <stdio.h>
#include <conio.h>

void main()
{
	int a;
	printf("Enter the number:");
	scanf("%d",&a);
	printf("\n");
	if(a%3==0)
	{
		printf("The number is a multiple of 3");
	}
	else
	{
		printf("The number is not a multiple of 3");
	}
	getch();
}
