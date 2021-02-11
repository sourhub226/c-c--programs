//sum of n nos
#include <stdio.h>

int add(int n)
{
	int x=0;
	if(n==0)
		return n;
	else
		x=n+add(n-1);
		return (x);
}
int main()
{
	int n,c;
	printf("Enter nth no: ");
	scanf("%d",&n);
	c=add(n);
	printf("Sum of first %d nos = %d",n,c);
}

