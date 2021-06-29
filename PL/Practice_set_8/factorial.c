//factorial of a no
#include <stdio.h>

int fact (int n)
{
	int f;
	if(n==1)
		return 1;
	else
		f=n*fact(n-1);
	return f;
}
int main()
{
	int x,n;
	printf("Enter a no: ");
	scanf("%d",&n);
	x=fact(n);
	printf("%d! = %d",n,x);
}
