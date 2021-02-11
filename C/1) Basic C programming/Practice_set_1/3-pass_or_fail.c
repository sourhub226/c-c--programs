//to enter 5 marks of a student and display if he has passed or failed(40 passing)
#include <stdio.h>

int main()
{
	int a,b,c,d,e,f,avg;
	printf("Enter marks of 5 subjects (out of 100): ");
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	
	avg=(a+b+c+d+e)/5;
	
	if(avg>40)
		printf("Passed");
	else
		printf("Failed");
		
	getch();
}
