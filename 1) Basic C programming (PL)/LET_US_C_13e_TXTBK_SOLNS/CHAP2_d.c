// Consider a currency system in which there are notes of seven denominations, namely, Rs. 1, Rs. 2, Rs. 5, Rs. 10, Rs. 50, Rs. 100. Is a sum of Rs. N is entered through the keyboard, write a program to compute the smallest number of notes that will combine to give Rs. N.
#include <stdio.h>

int main()
{
	int n, a, b, c, d, e, f;
	printf("Enter the amount in Rupees : ");
	scanf("%d",&n);
	printf("Rs.%d =",n);
	
	if (n >= 100)
	{
		a = n / 100;
		n = n % 100;
		printf("\n%d notes of Rs.100",a);
	
	}
	if (n >= 50)
	{
		b = n / 50;
		n = n % 50;
		printf("\n%d notes of Rs.50",b);
		
	}
	if (n >= 10)
	{
		c = n / 10;
		n = n % 10;
		printf("\n%d notes of Rs.10",c);
	
	}
	if (n >= 5)
	{
		d = n / 5;
		n = n % 5;
		printf("\n%d notes of Rs.5",d);
	
	}
	if (n >= 2)
	{
		e = n / 2;
		n = n % 2;
		printf("\n%d notes of Rs.2",e);
	
	}
	if (n >= 1)
	{
		f = n / 1;
		n = n % 1;
		printf("\n%d notes of Re.1",f);
	
	}
	getch();
}

