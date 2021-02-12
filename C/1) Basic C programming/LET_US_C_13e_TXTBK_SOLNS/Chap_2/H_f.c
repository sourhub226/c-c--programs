// If lengths of three sides of a triangle are input through the keyboard, write a program to find the area of the triangle.
#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,area,p;
	printf("Enter the lengths of 3 sides of a triangle: ");
	scanf("%f %f %f",&a,&b,&c);
	
	p=(a+b+c)/2;
	area=sqrt(p*(p-a)*(p-b)*(p-c));
	
	printf("Area of the triangle = %.2f sq.units",area);
	getch();
}
