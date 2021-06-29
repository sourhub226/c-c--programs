// If a five-digit number is input through the keyboard, write a program to calculate the sum of its digits. (Hint: Use the modulus operator ‘%’)
#include <stdio.h>

int main()
{
	int a,rem,sum=0;
	printf("Enter the number:");
	scanf("%d",&a);
	
	while(a>0)
	{
		rem=a%10;
		sum=sum+rem;
		a=a/10;
	}
	
	printf("The sum of digits of the entered number = %d",sum);
	getch();
}

