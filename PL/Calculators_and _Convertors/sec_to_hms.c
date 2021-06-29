// To convert time from seconds to hours,minutes,seconds
#include <stdio.h>

int main()
{
	int n,h,m,s;
	printf("Enter time in seconds: ");
	scanf("%d",&n);
	
	
	h=n/3600;
	m=(n%3600)/60;
	s=n-h*3600-m*60;
	
	printf("\n%d seconds = %d hour %d minutes %d seconds",n,h,m,s);
	
	getch();
}
