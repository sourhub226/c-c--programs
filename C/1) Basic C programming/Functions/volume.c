//Vol of sphere cube cylinder using functions
#include <stdio.h>
float volosphere (int);
float volocylinder (int,int);
float volocube (int);

int main()
{
	int a,r,h;
	float b;
	printf("To find Vol of\n1 --> Sphere\n2 --> Cylinder\n3 --> Cube\n");
	printf("Enter the appropriate no:");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			printf("Enter the radius: ");
			scanf("%d",&r);
			b=volosphere(r);
			printf("Vol of Sphere = %f",b);
			break;
			
		case 2:
			printf("Enter the radius and height: ");
			scanf("%d %d",&r,&h);
			b=volocylinder(r,h);
			printf("Vol of Cylinder = %f",b);
			break;
			
		case 3:
			printf("Enter the length: ");
			scanf("%d",&r);
			b=volocube(r);
			printf("Vol of Cube = %.2f",b);
			break;
	}
	
}

float volosphere(int r)
{
	return ((4*3.14*r*r*r)/3);
}
float volocylinder(int r,int h)
{
	return (3.14*r*r*h);
}
float volocube(int r)
{
	return (r*r*r);
}
