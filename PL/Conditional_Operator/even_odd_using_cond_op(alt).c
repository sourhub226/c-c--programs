// To check if a no. is even or odd
#include <stdio.h>

int main()
{
	int a;
	printf("Enter a no: ");
	scanf("%d",&a);
	
	char *p = a%2==0? "even":"odd";
	printf("%d is %s",a,p);
	
	getch();
}

