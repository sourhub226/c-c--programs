// To print pythagorian triplets upto n
#include <stdio.h>

int main()
{
	int i,j,k,c,d,n;
	printf("Enter the nth number: ");
	scanf("%d",&n);
	printf("\nPythagorian Triplets upto %d:\n",n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				c=(i*i)+(j*j);
				d=k*k;
				if(c==d)
					printf("(%d , %d , %d)\n",i,j,k);
			}
		}
	}
	getch();
}
