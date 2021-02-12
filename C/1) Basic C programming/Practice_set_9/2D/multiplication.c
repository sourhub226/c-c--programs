// To mulitply 2 matrix
#include <stdio.h>

int main()
{
	int a[100][100],b[100][100],c[100][100];
	int m,n,p,q,i,j,k,sum=0;
	printf("Enter rows and columns of matrix A: ");
	scanf("%d %d",&m,&n);
	printf("Enter rows and columns of matrix A: ");
	scanf("%d %d",&p,&q);
	printf("\n");
	if(n==p)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("Enter element a%d%d: ",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
		printf("\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("Enter element b%d%d: ",i+1,j+1);
				scanf("%d",&b[i][j]);
			}
		}
		printf("\n");
		
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				for(k=0;k<p;k++)
				{
					sum=sum+a[i][k]*b[k][j];
				}
				c[i][j]=sum;
				sum=0;
			}
		}
		printf("\nResultant Matrix:\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("%d\t",c[i][j]);
				
			}
			printf("\n");
		}
	}
	else
		printf("Matrix multiplication is not possible.");
		
}
