// Basic calc
#include<stdio.h>
#include<conio.h>

void main()
{
	float a,b,c;
	printf("\n Enter Value Of A:");
	scanf("%f",&a);
	printf("\n Enter Value Of B:");
	scanf("%f",&b);
	c=a+b;
	printf("\n Addition = %f",c);
	c=a-b;
	printf("\n Subtraction = %f",c);
	c=a*b;
	printf("\n Multiplication = %f",c);
	c=a*(1/b);
	printf("\n Division = %f",c);
	getch();
}
