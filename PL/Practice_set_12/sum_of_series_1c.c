//to diaplay and find sum of n terms in the series:
// 1/2+1/4+1/6+1/8+...+1/n
#include <stdio.h>

int main()
{
	float i,sum=0,n,e;
	printf("Enter n: ");
	scanf("%f",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		e=2*i;
		sum=sum+(1/e);
		if(i==n)
			printf("1/%.0f = %f",e,sum);
		else
			printf("1/%.0f + ",e);
	}
}
