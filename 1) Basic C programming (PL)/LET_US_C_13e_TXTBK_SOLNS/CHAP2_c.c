// If a four digit number is input through the keyboard, write a program to obtain the sum of the first and last digit of this number.
#include<stdio.h>

int main()
{
	int n,a,b,c,d;
	printf("Enter a 4 digit number: ");
	scanf("%d",&n);
	
	a=n/1000;
	b=n%10;
	
	printf("Sum of first and last digit of %d = %d",n,a+b);
	getch();

}
