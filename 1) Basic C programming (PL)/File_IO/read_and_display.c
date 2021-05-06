//to read content and display to user
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char ch;
	fp=fopen("txt1.txt","r");
	if(fp==NULL)
	{
		printf("The file cannot be opened");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF)
		printf("%c",ch);

	fclose(fp);
	
}
