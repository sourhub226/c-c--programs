#include <stdio.h>
#include <windows.h>

int main()
{
	int i=1,a;
	printf("Enter no. of times you want to hear beep sound: ");
	scanf("%d",&a);
	
	while(i<=a)
	{
		Beep(1000,500);
		i++;
	}
	getch();
}

