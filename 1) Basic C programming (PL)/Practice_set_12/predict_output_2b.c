//Predict the output of the following C program
#include <stdio.h>

int main()
{
	int pi,d,x=5,y=6,a=3,b=4;
	pi=(x++)-(--y)+(++x)+y;
	d=(++a)+(b++)-(b--);
	printf("pi=%d, d=%d",pi,d);
}
