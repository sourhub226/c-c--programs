//to determine if a no. is prime or not
#include <stdio.h>

int main()
{
	int n,flag=0,i;
	printf("Enter a no: ");
	scanf("%d",&n);
	
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
			flag=1;
			break;
	}
	if(flag==0)
		printf("%d is a prime no.",n);
	else
		printf("%d is not a prime no.",n);
	
	getch();
}
