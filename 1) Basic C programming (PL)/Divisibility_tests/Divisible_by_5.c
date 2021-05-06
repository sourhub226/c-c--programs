// To check is a number is divisible by 5
#include <stdio.h>
#include <conio.h>

void main()
{
	int a;
	printf("Enter the number:");
	scanf("%d",&a);
	printf("\n");
	if(a%5==0)
	{
		printf("The number is a multiple of 5");
	}
	else
	{
		printf("The number is not a multiple of 5");
	}
	getch();
}
