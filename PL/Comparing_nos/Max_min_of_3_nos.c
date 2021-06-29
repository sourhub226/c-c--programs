// To find max and min no among 3 nos
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,b,c;
	printf("Enter 1st number:");
	scanf("%d",&a);
	printf("\nEnter 2nd number:");
	scanf("%d",&b);
	printf("\nEnter 3rd number:");
	scanf("%d",&c);
	
	if(a>=b & a>=c)
	{
		if(b>=c)
		{
		printf("\nThe largest number is %d",a);
		printf("\nThe smallest number is %d",c);
		}
		else
		{
		printf("\nThe largest number is %d",a);
		printf("\nThe smallest number is %d",b);
		}
	
	}
	else if(b>=a & b>=c)
	{
		if(a>=c)
		{
		printf("\nThe largest number is %d",b);
		printf("\nThe smallest number is %d",c);
		}
		else
		{
		printf("\nThe largest number is %d",b);
		printf("\nThe smallest number is %d",a);
		}
	}
	else if(c>=a &c>=b)
	{
		if(a>=b)
		{
		printf("\nThe largest number is %d",c);
		printf("\nThe smallest number is %d",b);
		}
		else
		{
		printf("\nThe largest number is %d",c);
		printf("\nThe smallest number is %d",a);
		}
	}

	getch();
}

