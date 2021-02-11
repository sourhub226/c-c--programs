// To print a pyramid for a specific char
#include <stdio.h>
int pyramid (int,char);
int main()
{
	int l;
	char ch;
	printf("Enter no. of lines: ");
	scanf("%d",&l);
	printf("Enter the character: ");
	scanf(" %c",&ch);
	printf("\n");
	pyramid(l,ch);
	
}

int pyramid(int l,char ch)
{
	int i,j,k;
	for(i=1;i<=l;i++)
	{
		for (j=1;j<=(l-i);j++)
		{
			printf(" ");
		}
		for (k=1;k<=i;k++)
		{
			printf("%c ",ch);
		}
		printf("\n");
	}
	return 0;
}
