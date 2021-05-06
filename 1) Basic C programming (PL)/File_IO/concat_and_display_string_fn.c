//to concatenate 2 files and store output in another file using strings and display
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2,*f3;
	char s1[100],s2[100],s3[100];
	f1=fopen("txt2.txt","r");
	f2=fopen("txt3.txt","r");
	f3=fopen("concat2.txt","w+");
	if(f1==NULL||f2==NULL||f3==NULL)
	{
		printf("The files cannot be opened");
		exit(1);
	}

	while((fgets(s1,99,f1))!=NULL)
		fputs(s1,f3);
	while((fgets(s2,99,f2))!=NULL)
		fputs(s2,f3);

	printf("Merged file 1 and 2 into 3 successfully\n");
	printf("\nMerged output:\n");

	rewind(f3);
	while((fgets(s3,99,f3))!=NULL)
		printf("%s",s3);

	fclose(f1);
	fclose(f2);
	fclose(f3);

}
