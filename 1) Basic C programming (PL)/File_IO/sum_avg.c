//to read 5 nos from a file and find its sum and average and store in another file and display
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1,*f2;
	char ch;
	int i,sum=0,avg,num;
	f1=fopen("5int.txt","r");
	f2=fopen("sumavg.txt","w+");
	if(f1==NULL||f2==NULL)
	{
		printf("The files cannot be opened");
		exit(1);
	}
	
	for(i=1;i<=5;i++)
	{
		fscanf(f1,"%d",&num);
		sum=sum+num;
	}
	avg=sum/5;
	
	fprintf(f2,"Sum=%d\n",sum);
	fprintf(f2,"Avg=%d",avg);
	
	rewind(f2);
	while((ch=getc(f2))!=EOF)
		printf("%c",ch);
		
	fclose(f1);
	fclose(f2);
}
