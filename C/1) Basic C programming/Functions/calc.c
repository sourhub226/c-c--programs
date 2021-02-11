//Calculator using functions
#include <stdio.h>
float addition(float,float);
float subtraction(float,float);
float multiplication(float,float);
float division(float,float);

int main()
{
	float a,b,op;
	char o;
	printf("Enter 2 nos: ");
	scanf("%f %f",&a,&b);
	printf("Enter the operation to be performed (+,-,*,/): ");
	scanf(" %c",&o);
	
	switch(o)
	{
		case '+':
			op=addition(a,b);
			printf("%.2f+%.2f = %.4f",a,b,op);
			break;
			
		case '-':
			op=subtraction(a,b);
			printf("%.2f-%.2f = %.4f",a,b,op);
			break;
			
		case '*':
			op=multiplication(a,b);
			printf("%.2f*%.2f = %.4f",a,b,op);
			break;
			
		case '/':
			op=division(a,b);
			printf("%.2f/%.2f = %.4f",a,b,op);
			break;
	}
	
}

float addition(float a, float b)
{
	return (a+b);
}
float subtraction(float a, float b)
{
	return (a-b);
}
float multiplication(float a, float b)
{
	return (a*b);
}
float division(float a, float b)
{
	return (a/b);
}
