// To find nth prime no
#include <stdio.h>

int main()
{
	int n,i,j,flag,count=0;
	printf("Enter nth term:");
	scanf("%d",&n);
	printf("%dth Prime no:\n",n);
	
	for(i=1;i>=0;i++)
	{	
		flag=0;
		for(j=1;j<=i-1;j++)
		{
			if(i%j==0)
				flag++;
		}
		if(flag==1)	
			count++;
		if(count==n)
		{
			printf("%d\t",i);
			break;
		}
	}
}
