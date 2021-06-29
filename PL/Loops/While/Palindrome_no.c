// To check if a no is palindrome or not
#include <stdio.h>

int main()
{
	int n,rev=0,temp;
	printf("Enter a no: ");
	scanf("%d",&n);
	temp=n;
	
	while(n>0)
	{
		rev=rev*10+n%10;
		n=n/10;
	}
	
	if(rev==temp)
	{
		printf("%d is a palindrome number.",temp);
	}
	else
	{
		printf("%d is not a palindrome number.",temp);
	}
	getch();
	
}
	
