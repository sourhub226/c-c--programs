// To find sum of all diagonal elements in the array
#include <stdio.h>

int main()
{
	int a[100][100],sum=0,i,j,r,c;
	printf("Enter the rows and columns: ");
	scanf("%d %d",&r,&c);
	printf("\n");
	if(r==c)
	{
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
				if(i==j)
					sum=sum+a[i][j];
			}
		}
		printf("\nSum of diagonal elements = %d",sum);
	}
	else
		printf("Not a Square Matrix");
}
