//to write and read a file of integers and copy even and odd nos into 2 separate files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2,*f3;
	char s[100];
	int i,n,count=0,e=0,o=0,even,odd;
	f1=fopen("ints.txt","w+");
	f2=fopen("even.txt","w+");
	f3=fopen("odd.txt","w+");
	if(f1==NULL||f2==NULL||f3==NULL)
	{
		printf("The file cannot be opened");
		exit(1);
	}
	printf("Enter the integers:\n");
	while((strlen(gets(s)))>0)
	{
		count++;
		fputs(s,f1);
		fputs("\n",f1);
	}
	rewind(f1);
	for(i=1;i<=count;i++)
	{
		fscanf(f1,"%d",&n);
		if(n%2==0)
		{
			e++;
			fprintf(f2,"%d\t",n);
		}
		else
		{
			o++;
			fprintf(f3,"%d\t",n);
		}
	}
	printf("Operation successful");
	rewind(f2);
	rewind(f3);
	printf("Even nos:\n");
	for(i=1;i<=e;i++)
	{
		fscanf(f2,"%d\n",&even);
		printf("%d\n",even);
	}
	printf("Odd nos:\n");
	for(i=1;i<=o;i++)
	{
		fscanf(f3,"%d\n",&odd);
		printf("%d\n",odd);
	}
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
}


