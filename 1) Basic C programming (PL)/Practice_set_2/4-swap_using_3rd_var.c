//To swap 2 nos using a 3rd temp variable
#include <stdio.h>

int main()

{
	int a,b,c;
	printf("Enter the values of a and b: ");
	scanf("%d %d",&a,&b);
	
	c=a;
	a=b;
	b=c;
	
	printf("\nAfter swapping,\nThe values of a and b are: \n%d %d",a,b);
	
	getch();
}
