//to find area and perimeter of a circle
#include <stdio.h>

int circle(int *,int *,int *);
int main()
{
	int r,a,p;
	printf("Enter the radius of the circle: ");
	scanf("%d",&r);
	circle(&r,&a,&p);
	printf("\nArea=%d\nPerimeter=%d",a,p);
}
int circle(int *r,int *a,int *p)
{
	*a=3.14**r**r;
	*p=2*3.14**r;
}
