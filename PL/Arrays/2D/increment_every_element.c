// To increment every element in the array by 1
#include <stdio.h>

int main()
{
	int a[100][100],i,j,r,c;
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
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			a[i][j]=a[i][j]+1;
		}
	}
	printf("\nResultant Matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
}
