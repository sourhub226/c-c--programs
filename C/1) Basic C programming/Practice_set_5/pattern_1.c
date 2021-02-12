// To generate the pattern
// 		2 2 2 2 
// 		2 2 2 2 
// 		2 2 2 2 
// 		2 2 2 2
#include <stdio.h>

int main()
{
	int a,i,j;
	printf("Enter the number of rows (or columns):");
	scanf("%d",&a);
	printf("\n");
	
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=a;j++)
		{
			printf("2 ");
		}
		printf("\n");
	}
	getch();
}







