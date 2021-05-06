//to read 10 nos from the user and store only prime nos in a file and display it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1;
	char ch;
	int a,i,n,flag,x,count=0;
	f1=fopen("primenos.txt","w+");
	if(f1==NULL)
	{
		printf("The file cannot be opened");
		exit(1);
	}
	for(a=1;a<=10;a++)
	{
		flag=0;
		printf("Enter no %d: ",a);
		scanf("%d",&n);
		if(n==1)
			continue;
		for(i=2;i<=n-1;i++)
		{
			if(n%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			fprintf(f1,"%d\t",n);
			count++;
		}
	}
	rewind(f1);
 	for(a=1;a<=count;a++)
	{
		fscanf(f1,"%d",&x);
		printf("%d\t",x);
	}
	fclose(f1);

}

