//to check if a given month has 30 or 31 days
#include <stdio.h>

int main()
{
	int a;
	printf("Enter a no:");
	scanf("%d",&a);
	
	if(a==1|a==3|a==5|a==7|a==8|a==10|a==12)
		printf("The month has 31 days");
	else if(a==4|a==6|a==9|a==11)
		printf("The month has 30 days");
	else if (a==2)
		printf("The month has 28 days");
	else
		printf("There is no such month");
	
	getch();
}
