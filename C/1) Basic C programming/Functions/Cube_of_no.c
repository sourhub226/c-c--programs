// To calc cube of a no.
#include <stdio.h>
int cube(int);

void main()
{
	int a,b;
	printf("Enter a no: ");
	scanf("%d",&a);
	b=cube(a);
	printf("Cube of %d = %d",a,b);
	
}

int cube(int a)
{
	int c=a*a*a;
	return c;
}
