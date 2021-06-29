// To generate the pattern
// 		* * * * * 
// 		 * * * *
// 		  * * *
// 		   * *
// 		    *
#include <stdio.h>
#include <conio.h>

void main()
{
	int i,j,a,k;
	printf("Enter max number of stars in a rows:");
	scanf("%d",&a);
	
	for(i=a;i>=1;i--)
	{
		for(k=a;k>i;k--)
		{
			printf(" ");
		}
		
		for(j=1;j<=i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	getch();
}



