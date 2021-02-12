//Predict the output of the following C program
#include <stdio.h>

int main()
{
	int q,i=8,j=5;
	char c='c',d='d';
	float x=0.005,y=-0.001;
	q=(i-3*j)%(c+2*d)/(x-y);
	printf("q=%d",q);
}

