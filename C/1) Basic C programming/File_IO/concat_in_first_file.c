//to concatenate 2 files and store output in 1st file and display
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2;
	char ch;
	f1=fopen("merge1.txt","a+");
	f2=fopen("merge2.txt","r");
	if(f1==NULL||f2==NULL)
	{
		printf("The files cannot be opened");
		exit(1);
	}

	while((ch=getc(f2))!=EOF)
		fputc(ch,f1);
 	

	printf("Merged file 1 and 2 into 1 successfully\n");
	printf("\nMerged output:\n");

	rewind(f1);
	while((ch=getc(f1))!=EOF)
		printf("%c",ch);

	fclose(f1);
	fclose(f2);


}
