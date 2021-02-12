#include <stdio.h>
#include <string.h>
void main()
{
	char s[100];
	int i,j,a;
	printf("Enter the word: ");
	scanf(" %s",&s);
	a=strlen(s);
	for(i=0;i<a;i++)
		{
			for(j=0;j<=i;j++)
				printf("%c",s[j]);
				printf("\n");
		}
		for(i=a-2;i>=0;i--)
		{
			for(j=0;j<=i;j++)
				printf("%c",s[j]);
				printf("\n");
		}
	getch();
}
