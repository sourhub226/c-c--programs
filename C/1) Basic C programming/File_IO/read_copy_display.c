//to read content and write it to another file and display it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2;
	char ch1,ch2;
	f1=fopen("txt3.txt","r");
	f2=fopen("copy3.txt","w");
	if(f1==NULL||f2==NULL)
	{
		printf("The files cannot be opened");
		exit(1);
	}
	while((ch1=fgetc(f1))!=EOF)
	{
		fputc(ch1,f2);
	}
	fclose(f1);
	fclose(f2);
	
	f2=fopen("copy3.txt","r");
	if(f2==NULL)
	{
		printf("The file cannot be opened");
		exit(2);
	}
	while((ch2=fgetc(f1))!=EOF)
	{
		printf("%c",ch2);
	}
	fclose(f2);
}
