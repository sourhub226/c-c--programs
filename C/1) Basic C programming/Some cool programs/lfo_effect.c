#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	for(i=600;i>=15;i=i-15)
	{
		Beep(1000,i);			
	}
	getch();
}


