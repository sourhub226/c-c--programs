// Hashing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11
enum type_of_record {EMPTY,OCCUPIED,DELETED};

struct share
{
	int sid;
	float sprice;
	char *name;
};
struct record
{
	struct share srec;
	enum type_of_record status;
};

int hash(char item[])
{
	return(*item%MAX);
}

void insert(struct share sharec,struct record table[])
{
	int i,loc,h;
	h=hash(sharec.name);
	loc=h;
	for(i=1;i!=MAX-1;i++)
	{
		if(table[loc].status==EMPTY || table[loc].status==DELETED)
		{
			table[loc].srec=sharec;
			table[loc].status=OCCUPIED;
			printf("---Record inserted---\n");
			return;
		}
		if(strcmp(table[loc].srec.name,sharec.name)==0)
		{
			printf("---Duplicate---\n");
			return;
		}
		loc=(h+i)%MAX;
	}
	printf("---Record can't be inserted---\n");
}

int search(char key[],struct record table[])
{
	int i,h,loc;
	h=hash(key);
	loc=h;
	for(i=1;i!=MAX-1;i++)
	{
		if(table[loc].status==EMPTY)
			return -1;
		if(table[loc].status==OCCUPIED&&(strcmp(table[loc].srec.name,key)==0))
			return loc;
		loc=(h+i)%MAX;
	}
	return -1;
}

int del(char key[],struct record table[])
{
	int loc;
	loc=search(key,table);
	if(loc==-1)
	printf("Company not found\n");
	else
	{
		table[loc].status=DELETED;
		printf("---Record deleted---\n");
	}
}

void display(struct record table[])
{
	int i;
	for(i=0;i<MAX;i++)
	{
		printf("[%d]\t|\t",i);
		if(table[i].status==OCCUPIED)
		printf("Occupied: %s\n",table[i].srec.name);
		else if(table[i].status==DELETED)
		printf("Deleted\n");
		else
		printf("Empty\n");
	}
}

int main()
{
	int i,n,ch;
	char key[100];
	struct record table[MAX];
	struct share sharec;
	for(i=0;i<MAX-1;i++)
		table[i].status=EMPTY;
	
	printf("Enter no. of share companies: ");
	scanf("%d",&n);
	while(1)
	{
		printf("\n------------HASHING------------\n");
		printf("1.Insert a rec.\n");
		printf("2.Search a rec.\n");
		printf("3.Delete a rec.\n");
		printf("4.Display a rec.\n");
		printf("5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the details of share company in sorted order of name\n");
				for(i=0;i<n;i++)
				{	
					sharec.name=(char *)malloc(20*sizeof(char));
					printf("ID,Name,Price of company %d: ",i+1);
					scanf("%d %s %f",&sharec.sid,sharec.name,&sharec.sprice);
					insert(sharec,table);	
				}
				break;
			case 2:
				printf("Enter the share company name to be searched: ");
				scanf("%s",&key);
				i=search(key,table);
				if(i==-1)
					printf("Company not found\n");
				else
					printf("Company %s is found at [%d]\n",key,i);
				break;
			case 3:
				printf("Enter share company name to be deleted: ");
				scanf("%s",&key);
				i=del(key,table);
				break;
			case 4:
				display(table);	
				break;
			case 5:
				exit(1);
			default:
				printf("You have entered an incorrect option\n");	
		}			
    }
}
