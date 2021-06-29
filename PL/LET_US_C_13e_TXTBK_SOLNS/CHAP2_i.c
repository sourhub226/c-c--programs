// Write a program to receive values of latitude and longitude in degrees, of two places on earth and outputs the distance between them in nautical miles. The formula for distance in nautical: D=3963 * cos^-1 (sin l1 sin l2 + cos l1 cos l2 cos(g2-g1))
#include <stdio.h>
#include <math.h>

int main()
{
	float l1,l2,g1,g2,d;
	printf("Enter the values of latitude and longitude of first place: ");
	scanf("%f %f",&l1,&g1);
	printf("Enter the values of latitude and longitude of second place: ");
	scanf("%f %f",&l2,&g2);
	
	d=3963*acos(sin(l1)*sin(l2)+cos(l1)*cos(l2)*cos(g2-g1));
	
	printf("\nDistance between the 2 places = %.2f nautical miles",d);
	getch();
	
}
