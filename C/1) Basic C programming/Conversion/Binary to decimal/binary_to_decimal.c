// To convert from binary to decimal
#include <stdio.h>
#include <math.h>

int main()
{
	int a,rem,i=0,val=0,temp;
	printf("Enter a binary no.(0s and 1s): ");
	scanf("%d",&a);
	temp=a;
	
	while(a>=1)
	{
		rem=a%10;
		val=val+rem*(pow(2,i));
		a=a/10;
		i++;
	}
	
	printf("\nThe binary no. %d in decimal is written as %d",temp,val);
	
	getch();
}
