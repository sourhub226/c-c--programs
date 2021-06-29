//To generate multiplication table of a no.
#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Enter a number:");
	scanf("%d",&a);

	for(b=1; b<=10; b++)
	{
		c=a*b;
		printf("\n%d X %d = %d",a,b,c);
	}
	getch();
}
