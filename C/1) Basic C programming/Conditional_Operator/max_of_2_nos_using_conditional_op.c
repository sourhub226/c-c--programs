//to find the largest of 2 nos using conditional operator
#include <stdio.h>

int main()
{
	int a,b;
	printf("Enter value of a and b: ");
	scanf("%d %d",&a,&b);
		
	int large=(a>b? a:b);
	printf("The larger no is %d",large);
	
	getch();
}
