//Predict the output of the following C program
#include <stdio.h>

void main()
{
	int x,y,z,p;
	x=-1;
	y=1;
	z=++x|++y;
	p=x++&++y;
	printf("z=%d p=%d",z,p);
}


