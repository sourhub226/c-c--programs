#include <stdio.h>
#include <windows.h>

int main()
{
	int i=1;
	printf("Wake up!");
	
	while(i<=4)
	{
		Beep(2000,500);
		i++;
		Sleep(500);
	}
	i=1;
	while(i<=4)
	{
		Beep(2000,250);
		Beep(2000,250);
		i++;
		Sleep(500);
	}
	i=1;
	while(i)
	{
		Beep(2000,100);
		Beep(2000,100);
		Beep(2000,100);
		Beep(2000,100);
		i++;
		Sleep(600);
	}
	getch();
}


