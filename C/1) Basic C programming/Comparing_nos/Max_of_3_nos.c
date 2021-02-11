// To find max of 3 nos
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
	
	if(a>=b)
	{
		if(a>=c)
		{
			printf("\nThe largest number is %d",a);
		}
		else
		{
			printf("\nThe largest number is %d",c);
		}
		
	}
	else if(a<=b)
	{
		if(b>=c)
		{
			printf("\nThe largest number is %d",b);
		}
		else
		{
			printf("\nThe largest number is %d",c);
		}
	}
	
	getch();
}


