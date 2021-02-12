//pointer basic program
#include <stdio.h>

int main()
{
	int i=3;
	int *j;
	j=&i;
	printf("%u\n",&i);
	printf("%u\n",j);
	printf("%u\n",&j);
	printf("%u\n",j);
	printf("%d\n",i);
	printf("%d\n",*&i);
	printf("%d",*j);
}
