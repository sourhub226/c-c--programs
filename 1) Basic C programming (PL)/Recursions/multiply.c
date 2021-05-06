//Multiply 2 nos
#include <stdio.h>

int prod(int a,int b)
{
	if(b==0)
		return 0;
	else
		return (a+prod(a,b-1));
}
int main()
{
	int a,b,c;
	printf("Enter 2 nos: ");
	scanf("%d %d",&a,&b);
	c=prod(a,b);
	printf("Product = %d",c);
}
