//to concatenate 2 files and store output in another file and display
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2,*f3;
	char ch1,ch2,ch3;
	f1=fopen("txt1.txt","r");
	f2=fopen("txt2.txt","r");
	f3=fopen("concat.txt","w+");
	if(f1==NULL||f2==NULL||f3==NULL)
	{
		printf("The files cannot be opened");
		exit(1);
	}
	
	while((ch1=getc(f1))!=EOF)
		fputc(ch1,f3);
 	while((ch2=getc(f2))!=EOF)
		fputc(ch2,f3);
		
	printf("Merged file 1 and 2 into 3\n");
	printf("\nMerged output:\n");
	
	rewind(f3);
	while((ch3=getc(f3))!=EOF)
		printf("%c",ch3);
		
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
}
