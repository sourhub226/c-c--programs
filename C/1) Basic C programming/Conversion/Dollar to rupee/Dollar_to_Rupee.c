// To convert from dollar to rupee
#include<stdio.h>
#include<conio.h>

void main()
{
	float a,b;
	float dollar;
	printf("Enter today's Dollar rate: ");
	scanf("%f",&dollar);

	printf("\n Enter Dollar:");
	scanf("%f",&a);

	b=dollar*a;
	printf("\n Indian Rupee = %f",b);
	getch();
}
