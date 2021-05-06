//to check if a no is greater than 100 and even or odd
#include <stdio.h>

int main()
{
	int a;
	printf("Enter a no:");
	scanf("%d",&a);
	
	if(a>100 && a%2==0)
		printf("%d is greater than 100 and even",a);
	else if(a>100 && a%2!=0)
		printf("%d is greater than 100 and odd",a);
	else if(a<100 && a%2==0)
		printf("%d is even but not greater than 100",a);
	else if(a<100 && a%2!=0)
		printf("%d is odd but not greater than 100",a);
	else
		printf("100 is equal to 100 and even");
		
	getch();

}

