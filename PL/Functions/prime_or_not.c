// To check if a no is prime or not
#include <stdio.h>

int prime(int);
int main()
{
	int n,a;
	printf("Enter a no: ");
	scanf("%d",&n);
	a=prime(n);
	if(a==0)
		printf("%d is a prime no.",n);
	else
		printf("%d is not a prime no.",n);
	
}

int prime(int n)
{
	int flag=0,i;
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
			flag=1;
			break;
	}
	if(flag==0)
		return 0;
	else
		return 1;
}
