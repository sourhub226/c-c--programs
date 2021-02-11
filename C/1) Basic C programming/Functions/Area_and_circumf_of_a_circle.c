// To calc area and circumference of a circle
#include <stdio.h>
float area(float);
float cir(float);
int main()
{
	float r, a, c, m, n;
	printf("Enter the radius: ");
	scanf("%f", &r);
	m = area(r);
	n = cir(r);
	printf("Circumference = %f\nArea = %f", n, m);
	getch();
}

float area(float r)
{
	return (3.14 * r * r);
}
float cir(float r)
{
	return (2 * 3.14 * r);
}
