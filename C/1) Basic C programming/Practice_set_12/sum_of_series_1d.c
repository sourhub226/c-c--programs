//to diaplay and find sum of n terms in the series:
// 1^4+2^4+4^4+7^4+11^4+...+n^4
#include <stdio.h>
#include <math.h>

int main()
{
	int i,sum=0,n,x=1;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		x=x+(i-1);
		sum=sum+pow(x,4);
		if(i==n)
			printf("%d^4 = %d",x,sum);
		else
			printf("%d^4 + ",x);
	}
}
