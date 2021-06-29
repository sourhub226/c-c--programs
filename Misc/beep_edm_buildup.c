#include <stdio.h>
#include <windows.h>

int main()
{
	int i=1,a;
	printf("Enter no. of beats: ");
	scanf("%d",&a);
	
	while(i<=a)
	{
		Beep(1000,500);
		i++;
	}
	i=1;
	while(i<=a)
	{
		Beep(1000,250);
		i++;
	}
	i=1;
	while(i<=a+2)
	{
		Beep(1000,125);
		i++;
	}
	Beep(500,500);
	
	getch();
}
