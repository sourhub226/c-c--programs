// CGPA to percentage calc
#include <stdio.h>
#include <conio.h>

void main()
{
	float a,b;
	printf("Enter your CGPA:");
	scanf("%f",&a);
	
	b=a*9.55;
	
	printf("Percentage=%2.2f %%",b);
	
	getch();
}

