// To find square of a no
#include <stdio.h>
int square(int);

int main()
{
	int a,b;
	printf("Enter a no: ");
	scanf("%d",&a);
	b=square(a);
	printf("Square of %d = %d",a,b);
	getch();
}

int square(int a)
{
	int c=a*a;
	return c;
}
