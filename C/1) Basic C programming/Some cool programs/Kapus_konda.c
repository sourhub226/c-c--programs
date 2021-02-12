#include <stdio.h>
#include <string.h>
int main()
{
	int i=1;
	char a[100];
	char b[10]="stop";
	printf("Kapus kondya chi goshta sangu ka?\n");
	while(i>0)
	{
	printf("Answer:");
	scanf("%s",a);
	
	if (strcmp(a,b) == 0)
      {
      	printf("\nBara\n");
      	break;
      }
      printf("\n%s kay mahnte,kapus kondya chi goshta sangu ka?\n",a);
	}
	getch();
}
