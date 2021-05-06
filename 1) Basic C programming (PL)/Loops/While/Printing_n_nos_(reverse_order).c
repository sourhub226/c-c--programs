// To print n nos in reverse order
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,i;
	printf("Enter the n'th number: ");
	scanf("%d",&a);
	i=a;
	while(i>=1)
	{
		printf("%d\n",i);
		i--;
	}
	
	getch();
}


