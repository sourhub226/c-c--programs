// To generate the pattern
// 		1 1 1 1 1
// 		2 2 2 2 2
// 		3 3 3 3 3 
// 		4 4 4 4 4 
// 		5 5 5 5 5
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
			printf("%d ",i);
		}
		printf("\n");
	}
	getch();
}




