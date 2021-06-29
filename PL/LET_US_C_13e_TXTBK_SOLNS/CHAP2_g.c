// Write a program to receive cartesian coordinates (x,y) of a point and convert them into polar coordinates. (r,theta)
#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,r,t;
	printf("Enter cartesian co-ordinates (a,b): ");
	scanf("%f %f",&a,&b);
	
	r=sqrt((a*a)+(b*b));
	t=atan(b/a);
	
	printf("Cartesian co-ordinates (%.2f,%.2f) = Polar co-ordinates (%.2f,%.2f)",a,b,r,t);
}
