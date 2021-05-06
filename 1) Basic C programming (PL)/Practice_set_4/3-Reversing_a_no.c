//to reverse a given no.
#include <stdio.h>

int main()
{
	int a,rev=0;
	printf("Enter the number:");
	scanf("%d",&a);
	
	while(a>0)
	{
		rev=rev*10+a%10;
		a=a/10;
	}
	printf("The number in reversed order is %d",rev);
	getch();
}

