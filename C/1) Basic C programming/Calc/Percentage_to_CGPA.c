// Percentage to CGPA calc
#include <stdio.h>
#include <conio.h>

void main()
{
	float a,b;
	printf("Enter your percentage:");
	scanf("%f",&a);
	
	b=a/9.55;
	
	printf("CGPA=%1.1f",b);
	
	getch();
}
