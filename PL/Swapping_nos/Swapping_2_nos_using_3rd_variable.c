// To swap 2 nos using a temp var
#include<stdio.h>

void main()

{
	int a,b,c;
	printf("Enter the values of a and b: \n");
	scanf("%d %d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("\n");
	printf("After swapping,\nThe values of a and b are: \n%d %d",a,b);
	
	getch();
}
