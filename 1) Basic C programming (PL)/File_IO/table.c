//to create table of data and write it to a file and display it using fprintf and fscanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f1;
	char name[100];
	int age,sal,n,i;
	f1=fopen("table.txt","w+");
	if(f1==NULL)
	{
		printf("The file cannot be opened");
		exit(1);
	}
	printf("Enter no. of employees: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("Enter name of employee %d: ",i);
		scanf("%s",name);
		fprintf(f1,"%s\t",name);
		
		printf("Enter age of employee %d: ",i);
		scanf("%d",&age);
		fprintf(f1,"%d\t",age);
		
		printf("Enter salary of employee %d: ",i);
		scanf("%d",&sal);
		fprintf(f1,"%d\n",sal);
	}
 	rewind(f1);
	printf("Name\tAge\tSalary\n");
	for(i=1;i<=n;i++)
	{
		
		fscanf(f1,"%s",name);
		printf("%s\t",name);
		
		fscanf(f1,"%d",&age);
		printf("%d\t",age);
		
		fscanf(f1,"%d",&sal);
		printf("%d\n",sal);
	}
	fclose(f1);
	
}
