// To find factorial of a no.
#include <stdio.h>
int fact (int);
int main()
{
	int a;
	printf("Enter a no: ");
	scanf("%d",&a);
	int b=fact(a);
	printf("%d! = %d",a,b);
}

int fact (int a)
{
	int i,fact=1;
	for(i=1;i<=a;i++)
	{
		fact=fact*i;
	}
	return fact;
}
