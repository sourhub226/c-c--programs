//to find the largest of 3 nos using conditional operator
#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Enter value of a,b,c: ");
	scanf("%d %d %d",&a,&b,&c);
		
	int large=(a>b? (a>c? a:c):(b>c? b:c));
	printf("The largest no is %d",large);
	
	getch();
}
