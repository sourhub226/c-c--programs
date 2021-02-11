//to count no of digits in a no
#include <stdio.h>

int counter(int n)
{
	static int count=0;
	if (n!=0)
	{
		count++;
		counter(n/10);
	}
	else
		return count;
}
int main()
{
	int n,a;
	printf("Enter a no: ");
	scanf("%d",&n);
	a=counter(n);
	printf("No. of digits in %d = %d",n,a);
}
