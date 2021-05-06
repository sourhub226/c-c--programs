// To print squares of n nos 
#include <stdio.h>
int square(int);
int main()
{
	int i,n;
	printf("Enter the nth no: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		int a=square(i);
		printf("%d squared = %d\n",i,a);
	}
	getch();
}

int square(int i)
{
	return (i*i);
}
