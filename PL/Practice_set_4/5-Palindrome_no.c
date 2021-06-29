//to check if a no. is a palindrome no.
#include <stdio.h>

int main()
{
	int n,rem,sum=0,temp;
	printf("Enter a no: ");
	scanf("%d",&n);
	temp=n;
	
	while(n>0)
	{
		sum=sum*10+n%10;
		n=n/10;
	}
	
	if(sum==temp)
		printf("%d is a palindrome number.",temp);
	else
		printf("%d is not a palindrome number.",temp);
	getch();
	
}
	
