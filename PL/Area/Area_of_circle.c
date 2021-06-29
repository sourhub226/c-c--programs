//To find area of circle
#include<stdio.h>
#include<conio.h>

void main()
{
	float a,b;
	const float pi=3.141593;
	
	printf("Enter Radius:");
	scanf("%f",&a);

	b=pi*a*a;
	printf("Area of Circle = %f",b);
	getch();
}
