// To find asc and desc order of 3 nos
#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Enter 1st number:");
	scanf("%d",&a);
	printf("\nEnter 2nd number:");
	scanf("%d",&b);
	printf("\nEnter 3rd number:");
	scanf("%d",&c);
	
	if(a>=b & a>=c & b>=c)
	{
		printf("\nAscending order:%d,%d,%d",c,b,a);
		printf("\nDescending order:%d,%d,%d",a,b,c);
	}
	else if(a>=b & a>=c & c>=b)
	{
		printf("\nAscending order:%d,%d,%d",b,c,a);
		printf("\nDescending order:%d,%d,%d",a,c,b);
	}
	
	else if(b>=a & b>=c & a>=c)
	{
		printf("\nAscending order:%d,%d,%d",c,a,b);
		printf("\nDescending order:%d,%d,%d",b,a,c);
	}
	else if(b>=a & b>=c & c>=a)
	{
		printf("\nAscending order:%d,%d,%d",a,c,b);
		printf("\nDescending order:%d,%d,%d",b,c,a);
	}
	else if(c>=a & c>=b & a>=b)
	{
		printf("\nAscending order:%d,%d,%d",b,a,c);
		printf("\nDescending order:%d,%d,%d",c,a,b);
	}
	else if(c>=a & c>=b & b>=a)
	{
		printf("\nAscending order:%d,%d,%d",a,b,c);
		printf("\nDescending order:%d,%d,%d",c,b,a);
	}
	getch();
}

