// To check for leap year
#include <stdio.h>

int main()
{
	int a;
	printf("Enter the year: ");
	scanf("%d",&a);
	
	if(a%4==0)
	{
		printf("%d is a leap year",a);
	}
	else
	{
		printf("%d is not a leap year",a);
	}
	
	getch();
}
