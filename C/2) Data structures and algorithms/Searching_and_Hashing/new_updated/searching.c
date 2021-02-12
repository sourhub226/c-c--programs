// Searching
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct share
{
	int  sid;
	char *sname;
	float sprice;
};

void input(int n,struct share s[])
{
	int i;
	if(n==2||n==3)
		printf("\nEnter the details of share company in sorted order of name\n");
	else
		printf("\nEnter the details of share company\n");
	for(i=0;i<n;i++)
	{
		s[i].sname=(char*)malloc(sizeof(char)*20);
		printf("ID,Name,Price of company %d: ",i+1);
		scanf("%d %s %f",&s[i].sid,s[i].sname,&s[i].sprice);
	}
}

void display(int i,char *sharen)
{
	if(i==-1)
		printf("The company is not found\n");
	else
		printf("The company %s is found at location %d\n",sharen,i+1);
}

int linsrch(struct share s[],int n,char *sharen)
{
	int i=0;
	while((i<n)&&(strcmp(sharen,s[i].sname))!=0)	
		i++;
	if(i<n)
		return i;
	else
		return -1;	
}

int binsrch(struct share s[],int n,char *sharen)
{
	int low=0,up=0,mid=0;
	up=n-1;
	while(low<=up)
	{
		mid=(low+up)/2;
		if(strcmp(sharen,s[mid].sname)>0)
			low=mid+1;
		else if(strcmp(sharen,s[mid].sname)<0)
			up=mid-1;
		else
			return mid;		
	}
	return -1;
}

int recbinsrch (struct share s[],char *sharen,int low,int up)
{
	int mid;
	if(low>up)
		return -1;
	mid=(low+up)/2;
	if(strcmp(sharen,s[mid].sname)>0)
		recbinsrch(s,sharen,mid+1,up);
	else if (strcmp(sharen,s[mid].sname)<0)
		recbinsrch(s,sharen,low,mid-1);
	else
		return mid;
}

int main()
{
	int i,n,ch;
	char *sharen;
	sharen=(char*)malloc(sizeof(char)*20);
	struct share s[100];
	printf("Enter no of share companies: ");
	scanf("%d",&n);
	while(1)
	{
		int i=0;
		printf("\n-----------SEARCHING-----------\n");
		printf("1.Linear Search");
		printf("\n2.Binary Search");
		printf("\n3.Recursive Binary Search");
		printf("\n4.Exit");
		printf("\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				input(n,s);
				printf("\nEnter share company name to be searched: ");
				scanf("%s",sharen);
				i=linsrch(s,n,sharen);
				display(i,sharen);	
				break;
			case 2:
				input(n,s);
				printf("\nEnter share company name to be searched: ");
				scanf("%s",sharen);
				i=binsrch(s,n,sharen);
				display(i,sharen);
				break;
			
			case 3:
				input(n,s);
				printf("\nEnter share company name to be searched: ");
				scanf("%s",sharen);
				i=recbinsrch(s,sharen,0,n-1);
				display(i,sharen);	
				break;
			case 4:
				exit(1);	
			default:
				printf("You have entered an incorrect option\n");
		}
	}
}