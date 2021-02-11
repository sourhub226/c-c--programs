//To find larger of 4 different nos
#include <stdio.h>

int main()
{
	int a,b,c,d;
	printf("Enter 1st number:");
	scanf("%d",&a);
	printf("\nEnter 2nd number:");
	scanf("%d",&b);
	printf("\nEnter 3rd number:");
	scanf("%d",&c);
	printf("\nEnter 4th number:");
	scanf("%d",&d);
	
	if (a>=b)
	{
		if(a>=c)
		{
			if(a>=d)
			{
				printf("\nThe largest number is %d",a);
			}
			else
			{
				printf("\nThe largest number is %d",d);
			}
			
		}
		else if(a<=c)
		{
			if(c>=d)
			{
				printf("\nThe largest number is %d",c);
			}
			else
			{
				printf("\nThe largest number is %d",d);
			}
		}
	}
	else if(a<=b)
	{
		if(b>=c)
		{
			if(b>=d)
			{
				printf("\nThe largest number is %d",b);
			}
			else
			{
				printf("\nThe largest number is %d",d);
			}
		
		}
		else if(b<=c)
		{
			if(c>=d)
			{
				printf("\nThe largest number is %d",c);
			}
			else
			{
				printf("\nThe largest number is %d",d);
			}
		}
	}
	getch();
}



