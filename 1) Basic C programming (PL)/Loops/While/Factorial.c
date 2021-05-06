//To find factorial of a no.
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,n,i=1,fact=1;
	printf("Enter the number:");
	scanf("%d",&a);
	
	while (i<=a)
	{
		fact=fact*i;
		i++;
	} 
	printf("\n%d!=%d",a,fact);
	getch();
}
