//a total of 10% disc is offered if the total quantity is above 1000
#include <stdio.h>

int main()
{
	float q,p,t;
	printf("Enter the quantity: ");
	scanf("%f",&q);
	printf("Enter the price: ");
	scanf("%f",&p);
	t=p*q;
	if(q>1000)
	{
		t=t-(0.1*t);
	}
	printf("\nTotal selling price= Rs.%.2f",t);
		
	getch();
}
