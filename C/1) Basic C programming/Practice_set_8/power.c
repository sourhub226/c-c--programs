//Power of a no
#include <stdio.h>

int prod(int a,int b)
{
	if(b==0)
		return 1;
	else
		return (a*prod(a,b-1));
}
int main()
{
	int a,b,c;
	printf("Enter base and power: ");
	scanf("%d %d",&a,&b);
	c=prod(a,b);
	printf("%d^%d = %d",a,b,c);
}
