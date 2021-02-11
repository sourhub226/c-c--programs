// To find determinant of 2x2 matrix
#include <stdio.h>

int main()
{
	int a[100][100],i,j,s1=1,s2=1;
	printf("Determinant of 2x2 matrix\n\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(i==j)
				s1=s1*a[i][j];
			else
				s2=s2*a[i][j];
		}
	}
	printf("\nDeterminant = %d",s1-s2);
}
