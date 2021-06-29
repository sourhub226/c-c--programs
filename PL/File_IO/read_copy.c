//to read content and write it to another file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2;
	char ch;
	f1=fopen("txt2.txt","r");
	f2=fopen("copy2.txt","w");
	if(f1==NULL||f2==NULL)
	{
		printf("The files cannot be opened");
		exit(1);
	}
	while((ch=fgetc(f1))!=EOF)
	{
		fputc(ch,f2);
	}
	fclose(f1);
	fclose(f2);

}
