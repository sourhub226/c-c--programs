//to diaplay and find sum of n terms in the series:
// 1^2+2^2+3^2+...+n^2
#include <stdio.h>
#include <math.h>
int main()
{
	int i,sum=0,n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		sum=sum+pow(i,2);
		if(i==n)
			printf("%d^2 = %d",i,sum);
		else
			printf("%d^2 + ",i);
	}
}
