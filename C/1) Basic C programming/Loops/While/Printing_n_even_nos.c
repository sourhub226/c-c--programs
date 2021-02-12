// To print n even nos
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,i=2;
	printf("Enter the n'th number: ");
	scanf("%d",&a);
	
	while(i<=a)
	{
		printf("%d\n",i);
		i=i+2;
	}
	
	getch();
}


