//Predict the output of the following C program
#include <stdio.h>

int main()
{
	int i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(i==j)
				continue;
			printf("%d%d\n",i,j);
			if(j>i)
				break;
		}
	}
}
