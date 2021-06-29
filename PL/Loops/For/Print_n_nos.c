// To print n nos
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,i;
	printf("Enter the n'th number: ");
	scanf("%d",&a);
	
	for(i=1;i<=a;i++)
	{
		printf("%d\n",i);
	}
	
	getch();
}
