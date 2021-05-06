//To convert given integer (in days) to years,months,days
#include <stdio.h>

int main()
{
	int d,y,m,s;
	printf("Enter number of days: ");
	scanf("%d",&d);
	
	
	y=d/365;
	m=(d%365)/30;
	s=d-y*365-m*30;
	
	printf("\n%d days = %d year %d months %d days",d,y,m,s);
	
	getch();
}
