// Recursively reversing a single Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
}*start;

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}

void create()
{
	int i,data,n;
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	
	start=NULL;
	if (n==0)
		return;
	printf("Enter element to be inserted: ");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for(i=2;i<=n;i++)
	{
		printf("Enter element to be inserted: ");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	
}

void display()
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->link;
	}
}

struct node *reverse(struct node *start)
{
	if(start==NULL || start->link==NULL)
		return start;
		
	struct node *newstart;
	newstart=reverse(start->link);
	start->link->link=start;
	start->link=NULL;
	
	return newstart;
	
}

int main()
{
	create();	
	display();
	printf("\n\nReverse:\n");
	start=reverse(start);
	display();
}
