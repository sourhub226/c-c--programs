// To find if a no is even or odd
#include <stdio.h>
int eo(int);

int main()
{
	int a,b;
	printf("Enter a no: ");
	scanf("%d",&a);
	b=eo(a);
	
	if(b==0)
		printf("%d is even",a);
	else
		printf("%d is odd",a);
		
	getch();
}

int eo(int a)
{
	if(a%2==0)
		return 0;
	else
		return 1;
}
