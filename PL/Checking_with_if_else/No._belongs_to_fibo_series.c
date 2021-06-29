//to check if a no. belongs to fibonacci series
#include <stdio.h>

int main()
{
	int n,a=1,b=0,i=1,c=0,flag;
	printf("Enter the no: ");
	scanf("%d",&n);
	

	while(i>0)
	{	
		c=a+b;
		a=b;
		b=c;
		if (n==0)
		{	
			flag=2;
			printf("Belongs");
			break;
		}	
		else if (c==n)
		{
			flag=1;
			break;
		}	
		else if(c>n)
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		printf("Belongs");
	else if(flag==0)
		printf("not Belongs");
	getch();
}

