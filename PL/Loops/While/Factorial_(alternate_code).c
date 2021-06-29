//To find factorial of a no.
#include <stdio.h>

void main()
{
	int a=1,n,i=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	
	while(i<n)
	{
		a=a*(n-i);
		i++;
	}
	printf("%d! = %d",n,a);
	
	getch();
}

