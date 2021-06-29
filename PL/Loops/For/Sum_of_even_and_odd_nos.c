// To find sum of even and odd nos among 5 entered nos
#include <stdio.h>

int main()
{
	int a,i,sum=0,sumo=0;
	
	for(i=1;i<=5;i++)
	{
		printf("Enter number %d: ",i);
		scanf("%d",&a);
		
		if(a%2==0)
		{
			sum=sum+a;
		}
		else
		{
			sumo=sumo+a;
		}
		
	}
	printf("\nSum of even nos=%d",sum);
	printf("\nSum of odd nos=%d",sumo);
	
	getch();
}
