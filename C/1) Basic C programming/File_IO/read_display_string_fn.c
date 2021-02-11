//to read content and display to user using strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char s[100];
	fp=fopen("txt2.txt","r");
	if(fp==NULL)
	{
		printf("The file cannot be opened");
		exit(1);
	}
	while((fgets(s,79,fp))!=NULL)
		printf("%s",s);

	fclose(fp);

}
