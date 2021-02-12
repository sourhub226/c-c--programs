// To swap 2 nos without using a temp var
#include<stdio.h>

void main()

{
	int a,b;
	printf("Enter the values of a and b: \n");
	scanf("%d %d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("\n");
	printf("After swapping,\nThe values of a and b are \n%d %d",a,b);
	
	getch();
}
