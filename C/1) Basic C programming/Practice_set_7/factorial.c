//to find factorial of a no using functions
#include <stdio.h>

int factorial(int *, int *);
int main()
{
	int a,f=1;
	printf("Enter a no: ");
	scanf("%d",&a);
	factorial(&a,&f);
	printf("%d! = %d",a,f);
}
int factorial(int *a,int *f)
{
	int i;
	for(i=1;i<=*a;i++)
	{
		*f=*f*i;
	}
}
