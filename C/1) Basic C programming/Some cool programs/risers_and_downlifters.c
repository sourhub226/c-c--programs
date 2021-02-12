#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	printf("Sweep up");
	for(i=1;i<=4500;i=i+100)
	{
		Beep(i,90);
	}
	printf("\nSweep down");
	for(i=4500;i>=0;i=i-100)
	{
		Beep(i,90);
	}
	getch();
}


