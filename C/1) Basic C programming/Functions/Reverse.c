// To reverse a number
#include <stdio.h>

int reverse (int);
int main()
{
	int n,a;
	printf("Enter a no: ");
	scanf("%d",&n);
	
		a=reverse(n);
		printf("Reversed order = %d",a);
	getch();
}

int reverse(int n)
{
	int rev=0;
	if(n)
	{
		rev=rev*10+n%10;
		n=n/10;
		reverse(n);
	}
	else
		return rev;
}
