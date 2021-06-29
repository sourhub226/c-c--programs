#include <stdio.h>

int main()
{
	struct patient
	{
		int weight;
		float age;

	}p1;

	union doctor
	{
		int weight;
		float age;
		char man;
	}d1;
	
	printf("%d",sizeof(p1));
	printf("\n%d",sizeof(d1));
}
