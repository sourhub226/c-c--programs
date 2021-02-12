// To generate the pattern
// 		*
// 		* *
// 		* * * 
// 		* * * * 
// 		* * * * *
#include <stdio.h>

int main()
{
	int i,j,a;
	printf("Enter number of rows:");
	scanf("%d",&a);
	printf("\n");
	
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	getch();
}




