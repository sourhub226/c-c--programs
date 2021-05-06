// To generate the pattern
// 		    *
// 		   **
// 		  ***
// 		 ****
// 		*****
#include <stdio.h>
#include <conio.h>

void main()
{
	int i,j,a,k;
	printf("Enter max number of stars in a rows:");
	scanf("%d",&a);
	
	for(i=1;i<=a;i++)
	{
		for(k=1;k<=(a-i);k++)
		{
			printf(" ");
		}
		
		
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	getch();
}

