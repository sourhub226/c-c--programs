//to find the largest of 4 nos using conditional operator
#include <stdio.h>

int main()
{
	int a, b, c, d;
	printf("Enter 4 nos: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	int large = a > b ? (a > c ? (a > d ? a : d) : (c > d ? c : d))
					  : (b > c ? (b > d ? b : d) : (c > d ? c : d));
	printf("The largest no. is %d", large);

	getch();
}
