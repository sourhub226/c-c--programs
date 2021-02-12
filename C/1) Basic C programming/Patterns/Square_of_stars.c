// To generate the pattern
// 		* * * *
// 		* * * * 
// 		* * * *
// 		* * * *  
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,i,j;
	printf("Enter the number of rows (or columns):");
	scanf("%d",&a);
	printf("\n");
	
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=a;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	getch();
}
