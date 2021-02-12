// To find trigonometric values
#include<stdio.h>
#include<math.h>

void main()
{
	float a,b,c,d,e,f,g,h;

	printf("Enter angle in Degrees:");
	scanf("%f",&a);

	b=a*(3.141592653589793/180);
	c=sin(b);
	d=cos(b);
	e=tan(b);
	f=1/sin(b);
	g=1/cos(b);
	h=1/tan(b);
	printf("\nSin= %f",c);
	printf("\nCos= %f",d);
	printf("\nTan= %f",e);
	printf("\nCosec= %f",f);
	printf("\nSec= %f",g);
	printf("\nCot= %f",h);
	getch();
	
}
