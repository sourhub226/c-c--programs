// To find prime nos from 1 to n
#include <stdio.h>

int main()
{
	int n,i,j,flag=0;
	printf("Enter nth no:");
	scanf("%d",&n);
	printf("Prime nos upto %d:\n",n);
	
	for(i=1;i<=n;i++)
	{	
		flag=0;
		for(j=1;j<=i-1;j++)
		{
			if(i%j==0)
				flag++;
		}
		if(flag==1)	
			printf("%d\t",i);
	}
}
