//to find area, circumference and diameter of a circle
#include <stdio.h>
int circle(int *,int *,int *,int *);
int main()
{
	int r,a,p,d;
	printf("Enter the radius of the circle: ");
	scanf("%d",&r);
	circle(&r,&d,&a,&p);
	printf("\nDiameter=%d\nArea=%d\nPerimeter=%d",d,a,p);
}
int circle(int *r,int *d,int *a,int *p)
{
	*d=2**r;
	*a=3.14**r**r;
	*p=2*3.14**r;
}
