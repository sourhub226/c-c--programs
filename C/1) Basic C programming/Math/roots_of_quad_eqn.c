// To find roots of a quadratic eqn
#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,d,x1,x2;
	printf("To calculate roots of the quadratic eqn ax^2+bx+c\n");
	printf("Enter values of a,b,c :\n");
	scanf("%f %f %f",&a,&b,&c);
	
	d=sqrt((b*b)-(4.00*a*c));
	x1=(-b+d)/(2.00*a);
	x2=(-b-d)/(2.00*a);
	
	if(d>0)
	{
		printf("\nThe 2 roots are real and unequal\n");
		printf("\nThe roots of the quadratic eqn are:\nx=%.4f and x=%.4f",x1,x2);
	}
	else if(d==0)
	{
		printf("\nThe 2 roots are real and equal\n");
		printf("\nThe roots of the quadratic eqn are:\nx=%.4f and x=%.4f",x1,x2);
	}
	else
	{
		printf("\nThe 2 roots are imaginary\n");
		d=sqrt((4.00*a*c)-(b*b));
		printf("\nThe roots of the quadratic eqn are:\nx=%.4f+%.4fi and x=%.4f%.4fi",(-b/(2*a)),(d/(2*a)),(-b/(2*a)),(-d/(2*a)));
	}
	
	getch();
}
