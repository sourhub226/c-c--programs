// To generate the pattern
// 		A
// 		B C
// 		D E F
// 		G H I J
#include <stdio.h>

int main()
{
	int i,j,a;
	char k='A';
	printf("Enter number of rows:");
	scanf("%d",&a);
	printf("\n");
	
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%c ",k++);
		}
		printf("\n");
	}
	getch();
}





