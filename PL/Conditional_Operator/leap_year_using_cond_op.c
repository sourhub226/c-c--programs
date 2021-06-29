// To check if a year is leap year
#include <stdio.h>

int main()
{
	int a;
	printf("Enter the year: ");
	scanf("%d",&a);
	
	a%4==0? printf("%d is a leap year",a):printf("%d is not a leap year",a);
	
	getch();
}
