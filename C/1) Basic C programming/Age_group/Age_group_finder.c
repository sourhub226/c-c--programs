//To find your age group
#include<stdio.h>
#include<conio.h>

void main()
{
	int age;
	printf("Enter your age:");
	scanf("%d", &age);
	
	if(age<=1)
	{
		printf("You are an Infant \n");
	}
	
	if(age>1 & age<=3)
	{
		printf("You are a Toddler \n");
		
	}
	
	if(age>3 & age<=6) 
	{
		printf("You are a Preschooler \n");
	}
	
	if(age>6 & age<=12)
	{
		printf("You are a School age child \n");
	}
	
    if(age>12 & age<=18)
	{
		printf("You are an Adolescent \n");
	}
	
	if(age>18)
	{
		printf("You are an Adult \n");
	}
	getch();
	
}
