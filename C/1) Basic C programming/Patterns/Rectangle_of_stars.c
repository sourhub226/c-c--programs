// To generate the pattern
// 		* * * *
// 		* * * * 
// 		* * * * 

#include <stdio.h>
#include <conio.h>

void main()
{
	int a,b,i,j;
	printf("Enter the number of rows:");
	scanf("%d",&a);
	printf("Enter the number of columns:");
	scanf("%d",&b);
	printf("\n");
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=b;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	getch();
}
