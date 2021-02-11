//to print multiplication table of a no.
#include <stdio.h>

int main()
{ 
	int a,i=1,b;
	printf("Enter the number:");
	scanf("%d",&a);
	
	while (i<=10)
	{
		b=a*i;
		printf("\n%d X %d = %d",a,i,b);
		i++;
	}
	getch();
}
