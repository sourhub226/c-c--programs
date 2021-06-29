//to print first n natural nos using while loop
#include <stdio.h>

int main()
{
	int n,i=1;
	printf("Enter the nth number: ");
	scanf("%d",&n);
	
	while(i<=n)
	{
		printf("%d\n",i);
		i++;
	}
	
	getch();
}

