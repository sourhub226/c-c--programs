//To convert temperature from fahrenheit to degree celcius
#include <stdio.h>

int main()
{
	float fah,c;
	printf("Enter the temperature in Fahrenheit: ");
	scanf("%f",&fah);
	
	c=(5*(fah-32))/9;
	
	printf("The temperature in degree celcius is: %f",c);
	
	getch();
}
