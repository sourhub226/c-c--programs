// To print n nos in reverse order
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,i;
	printf("Enter the n'th number: ");
	scanf("%d",&a);
	
	for(i=a;i>=1;i--)
	{
		printf("%d\n",i);
	}
	
	getch();
}

