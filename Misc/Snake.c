#include <stdio.h>

int main()
{
	int l,t,i,j,s,r,k;
	printf("Enter length and thickness of the snake: ");
	scanf("%d %d",&l,&t);
	
	for(r=1;r<=l;r++)
	{
		for(j=1;j<=t;j++)
		{
			for(s=1;s<=j-1;s++)
			{
				printf(" ");
			}
			printf("*\n");
		}
		for(i=1;i<=t;i++)
		{
			for(k=1;k<=(t-i);k++)
			{
				printf(" ");
			}
			printf("*");
			printf("\n");
		}
	}
}
