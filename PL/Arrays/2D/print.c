// To print all elements in the matrix
#include <stdio.h>

int main()
{
	int arr[100][100],i,j,r,c;
	printf("Enter the rows and columns: ");
	scanf("%d %d",&r,&c);
	printf("\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nEntered Matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
}
