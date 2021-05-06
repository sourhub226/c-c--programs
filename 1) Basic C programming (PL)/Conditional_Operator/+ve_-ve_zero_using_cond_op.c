// To check if a no. is +ve or -ve
#include <stdio.h>

int main()
{
	int a;
	printf("Enter a no: ");
	scanf("%d",&a);
	
	a>0? printf("%d is positive",a):(a<0? printf("%d is negative",a):printf("The entered no. is zero"));
	
	getch();
}
