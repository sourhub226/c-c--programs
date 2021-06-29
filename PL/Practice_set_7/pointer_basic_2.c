//pointer basic prog 2
#include <stdio.h>

int main()
{
	int i=3,*j,**k;
	j=&i;
	k=&j;
	printf("%u\n",&i);
	printf("%u\n",j);
	printf("%u\n",*k);
	printf("%u\n",&j);
	printf("%u\n",k);
	printf("%u\n",&k);
	printf("%u\n",j);
	printf("%u\n",k);
	printf("%u\n",i);
	printf("%u\n",*&i);
	printf("%u\n",*j);
	printf("%u\n",**k);
}
