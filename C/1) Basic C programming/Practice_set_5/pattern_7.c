// To generate the pattern
// 		*********
// 		 *******
// 		  *****
// 		   ***
// 			*
#include <stdio.h>

int main()
{
	int i,j,a,k;
	printf("Enter number of rows:");
	scanf("%d",&a);
	printf("\n");
	for(i=a;i>=1;i--)
	{
		for(k=a;k>i;k--)
		{
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	getch();
}















