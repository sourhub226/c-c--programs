// To implement babylonian method to calculate sqaure roots of a no.
#include <stdio.h>

void main()
{
	float num,i,j,temp;
	printf("Enter the number whose square root is to be found out:");
	scanf("%f",&num);
	printf("\nBy Babylonian method,\n");
	printf("\n");
	
	for(i=num;i>temp;i)
	{
		j=num/i;
		printf("%f\t%f\n",i,j);
		i=(i+j)/2;
		temp=j+0.0001;
	}

	printf("\nHence square root of %f is %f",num,i);
	
	getch();
}
