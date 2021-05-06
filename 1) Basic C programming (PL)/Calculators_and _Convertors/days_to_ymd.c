//To convert given integer (in days) to years,months,days
#include <stdio.h>

int main()
{
	int d,y,m,n;
	printf("Enter number of days: ");
	scanf("%d",&n);
	
	
	y=n/365;
	m=(n%365)/30;
	d=n-y*365-m*30;
	
	printf("\n%d days = %d year %d months %d days",n,y,m,d);
	
	getch();
}
