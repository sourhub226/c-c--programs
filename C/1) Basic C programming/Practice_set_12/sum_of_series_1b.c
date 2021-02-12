//to diaplay and find sum of n terms in the series:
// 1/1+1/3+1/5+1/7+...+1/n
#include <stdio.h>

int main()
{
	float i,sum=0,n,o;
	printf("Enter n: ");
	scanf("%f",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		o=(2*i-1);
		sum=sum+(1/o);
		if(i==n)
			printf("1/%.0f = %f",o,sum);
		else
			printf("1/%.0f + ",o);
	}
}
