//To swap 2 nos without using 3rd variable
#include<stdio.h>

int main()

{
	int a,b;
	printf("Enter the values of a and b: ");
	scanf("%d %d",&a,&b);
	
	a=a+b;
	b=a-b;
	a=a-b;
	
	printf("\nAfter swapping,\nThe values of a and b are \n%d %d",a,b);
	
	getch();
}
