// To find product of 2 nos
#include <stdio.h>
int prod(int,int);

int main()
{
	int a,b,c;
	printf("Enter 2 nos: ");
	scanf("%d %d",&a,&b);
	c=prod(a,b);
	printf("Product=%d",c);
	getch();
}

int prod(int a,int b)
{
	return (a*b);
}
