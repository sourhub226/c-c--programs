//To check if a number is divisible by 10
#include <stdio.h>

int main()
{
	int a;
	printf("Enter the number:");
	scanf("%d",&a);
	
	if(a%10==0)
	{
		printf("\nThe number is divisible by 10");
	}
	else
	{
		printf("\nThe number is not divisible by 10");
	}
	getch();
}

