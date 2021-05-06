// Merging of 2 single Linked List
#include <stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;	
}*start1=NULL,*start2=NULL,*start3=NULL;

struct node *insert(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if (start==NULL)
	{
		tmp->link=start;
		start=tmp;
		return start;
	}
	else
	{
		p=start;
		while(p->link!=NULL)
			p=p->link;
		p->link=tmp;
		tmp->link=NULL;
		return start;
	}
}

struct node *create(struct node *start)
{
	int i,n,info;
	printf("Enter no of items: ");
	scanf("%d",&n);
	start=NULL;
	
	if(n==0)
		return start;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the item: ");
		scanf("%d",&info);
		start=insert(start,info);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty");
		return start;
	}
	
	p=start;
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->link;
	}
	return start;
}

void merge(struct node *p1,struct node *p2)
{
	while(p1!=NULL &&p2!=NULL)
	{
		if (p1->info<p2->info)
		{
			start3=insert(start3,p1->info);
			p1=p1->link;
		}
		else if (p1->info>p2->info)
		{
			start3=insert(start3,p2->info);
			p2=p2->link;
		}
		else if (p1->info==p2->info)
		{
			start3=insert(start3,p1->info);
			p1=p1->link;
			p2=p2->link;
		}
	}
	while(p1!=NULL)
	{
		start3=insert(start3,p1->info);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		start3=insert(start3,p2->info);
		p2=p2->link;
	}
}

int main()
{
	printf("Enter List 1 elements in sorted order:\n");
	start1=create(start1);
	printf("\nEnter List 2 elements in sorted order:\n");
	start2=create(start2);
	printf("\nList 1 elements:\n");
	start1=display(start1);
	printf("\nList 2 elements:\n");
	start2=display(start2);
	merge(start1,start2);
	printf("\n\nMerged List elements:\n");
	display(start3);
}
