// To convert from decimal to binary
#include <stdio.h>
#include <math.h>

int main()
{
	int a,rem,i=0,val=0,temp;
	printf("Enter a decimal no: ");
	scanf("%d",&a);
	temp=a;
	
	while(a>=1)
	{
		rem=a%2;
		val=val+rem*(pow(10,i));
		a=a/2;
		i++;
	}
	
	printf("\nThe decimal no %d in binary is written as %d",temp,val);
	
	getch();
}

