// To print n nos
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,i=1;
	printf("Enter the n'th number: ");
	scanf("%d",&a);
	
	while(i<=a)
	{
		printf("%d\n",i);
		i++;
	}
	
	getch();
}

