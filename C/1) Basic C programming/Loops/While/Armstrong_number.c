// To check if a no is armstrong no or not
#include <stdio.h>
#include <conio.h>

void main()
{
	int a,temp,rem,sum=0;
	printf("Enter the number:");
	scanf("%d",&a);
	temp=a;
	
	while(a>0)
	{
		rem=a%10;
		sum=sum+(rem*rem*rem);
		a=a/10;
	}
	
	if(sum==temp)
	printf("%d is an Armstrong number.",temp);
	else
	printf("%d is not an Armstrong number.",temp);
	
	getch();
}
