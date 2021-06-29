//To find larger of 2 given nos
#include <stdio.h>

int main()
{
	int a,b;
	printf("Enter 1st number:");
	scanf("%d",&a);
	printf("\nEnter 2nd number:");
	scanf("%d",&b);
	
	if(a>b)
	{
		printf("\nThe largest number is %d",a);
	}
	else if(a<b)
	{
		printf("\nThe largest number is %d",b);
	}
	else
	{
		printf("\nBoth numbers are equal");
	}
	getch();
}
