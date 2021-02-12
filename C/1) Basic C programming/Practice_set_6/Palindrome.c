//To check if a no is palindrome or not using functions
#include <stdio.h>
int pal(int);
int main()
{
	int a;
	printf("Enter a no:");
	scanf("%d",&a);
	int b=pal(a);
	if (b==a)
		printf("%d is a palindrome no.",a);
	else
		printf("%d is not a palindrome no.",a);
}

int pal(int a)
{
	int rev=0;
	while(a>0)
	{
		rev=rev*10+a%10;
		a=a/10;
	}
	return rev;
}
