// If a five-digit number is input through the keyboard, write a program to print a new number by adding one to each of its digits. For example, if the number that is input is 12391 then the output should be displayed as 23402.
#include <stdio.h>

int main()
{
	int n;
	printf("Enter a 5 digit number: ");
	scanf("%d",&n);
	
	n=n+11111;
	
	printf("The required no. is %d",n);
	getch();
}
