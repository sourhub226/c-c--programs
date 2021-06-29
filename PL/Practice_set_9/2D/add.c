// To add 2 matrix
#include <stdio.h>

int main()
{
	int a[100][100],b[100][100],sum[100][100],i,j,r,c;
	printf("Enter the rows and columns: ");
	scanf("%d %d",&r,&c);
	printf("\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element b%d%d: ",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sum[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("\nSum of Matrices:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}
	
}
