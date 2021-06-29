// To reverse a given no.
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,rem;
	printf("Enter the number:");
	scanf("%d",&a);
	
	printf("The number in reversed order is ");
	while(a>0)
	{
		rem=a%10;
		printf("%d",rem);
		a=a/10;
	}
	
	getch();
}
