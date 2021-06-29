// To swap 3 nos using a temp var
#include <stdio.h>

int main()
{
	int a,b,c,temp;
	printf("Enter 3 nos: ");
	scanf("%d %d %d",&a,&b,&c);
	
	temp=a;
	a=c;
	c=b;
	b=temp;
	
	printf("\nAfter swapping,\nThe 3 nos are %d %d %d",a,b,c);
	getch();
}
