// To calc your BMI
#include <stdio.h>
#include <conio.h>

void main()

{
	float feet,i,m1,m2,m,wt,bmi;
	
	
	printf("Enter your Height in Feet-Inches (Hit space after feet): \n");
	scanf ("%f" "%f", &feet, &i);
	printf("\n");
	
	printf("Enter your Weight in Kg: \n");
	scanf ("%f", &wt);
	printf("\n");
	
	m1=0.3048*feet;
	m2=0.0254*i;
	m=m1+m2;
	
	bmi=wt/(m*m);
	
	printf("BMI=%f \n",bmi);
	printf("\n");
	
	if(bmi<18.5)
	{
		printf("You are Underweight");
	}
	if(bmi>=18.5 & bmi<=22.9)
	{
		printf("You are Normal");
	}
	if(bmi>=23 & bmi<=24.9)
	{
		printf("You are Overweight");
	}
	if(bmi>=25 & bmi<=29.9)
	{
		printf("You are Pre-Obese");
	}
	if(bmi>=30)
	{
		printf("You are Obese");
	}
	
	
	getch();
	
}
