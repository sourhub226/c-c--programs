// To generate the pattern
// 		1
// 		2 3
// 		4 5 6 
// 		7 8 9 10
#include <stdio.h>

int main()
{
	int i,j,a,k=1;
	printf("Enter number of rows:");
	scanf("%d",&a);
	printf("\n");
	
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",k++);
		}
		printf("\n");
	}
	getch();
}






