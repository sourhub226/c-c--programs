// To find sum of n nos
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,n,i,sum=0;
	printf("Enter the nth number:");
	scanf("%d",&a);
	
	for(i=0;i<=a;i++)
	{
		sum=sum+i;
	}
	printf("\nSum of first %d numbers=%d",a,sum);
	getch();
}
