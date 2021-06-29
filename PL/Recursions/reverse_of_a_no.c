//reverse of a no
#include <stdio.h>

int reverse(int n)
{
	static int rev=0;
	if (n!=0)
	{
		rev=rev*10+n%10;
		reverse(n/10);
	}
	else
		return rev;
}
int main()
{
	int n,a;
	printf("Enter a no: ");
	scanf("%d",&n);
	a=reverse(n);
	printf("%d in reverse order is %d",n,a);
}
