////To find area of cuboid
#include<stdio.h>
#include<conio.h>

void main()
{
	float a,b,c,d;

	printf("\n Enter Length:");
	scanf("%f",&a);
	printf("\n Enter Breadth:");
	scanf("%f",&b);
	printf("\n Enter Height:");
	scanf("%f",&c);
	d=2*((a*b)+(b*c)+(c*a));
	printf("\n Area of Cuboid = %f",d);
	getch();
}
