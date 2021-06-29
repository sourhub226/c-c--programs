// To find prime nos upto n terms
#include <stdio.h>

int main()
{
	int n,i,j,flag,count=0;
	printf("Enter nth term:");
	scanf("%d",&n);
	printf("First %d Prime nos:\n",n);
	
	for(i=1;i>=0;i++)
	{	
		flag=0;
		for(j=1;j<=i-1;j++)
		{
			if(i%j==0)
				flag++;
		}
		if(flag==1)	
		{	printf("%d\t",i);
			count++;
		}
		if(count==n)
			break;
	}
}
