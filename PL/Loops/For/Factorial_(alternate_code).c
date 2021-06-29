//To find factorial of a no.
#include <stdio.h>

void main()
{
	int a=1,n,i;
	printf("Enter the number: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		a=a*(n-i);
	}
	printf("%d! = %d",n,a);
	
	getch();
}
