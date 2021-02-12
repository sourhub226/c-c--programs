//to find larger of 3 nos using functions
#include <stdio.h>

int large(int*, int*,int *,int *);
int main()
{
	int a,b,c,l;
	printf("Enter 3 nos: ");
	scanf("%d %d %d",&a,&b,&c);
	large(&a,&b,&c,&l);
	printf("%d is the largest no.",l);
}
int large(int *a, int *b,int *c,int *l)
{
	*l=*a>*b? ((*a>*c)? *a:*c):(*b>*c? *b:*c);
}
