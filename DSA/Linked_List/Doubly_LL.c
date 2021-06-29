// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int info;
	struct node *next;
	struct node *prev;
}*start;

void addatbeg(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
}

void addatemp(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
}

void addatend(int data)
{
	struct node *tmp,*p;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
}

int addafter(int data,int item)
{
	struct node *tmp,*p;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp->prev=p;
			tmp->next=p->next;
			if(p->next!=NULL)
				p->next->prev=tmp;
			p->next=tmp;
			return 1;
		}
		p=p->next;	
	}
	printf("\nElement not found\n");
	return 0;
}

int addbefore(int data,int item)
{
	struct node *tmp,*q;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return 0;
	}
	if(start->info==item)
	{
		tmp->prev=NULL;
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		return 1;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
			tmp->prev=q->prev;
			tmp->next=q;
			q->prev->next=tmp;
			q->prev=tmp;
			return 1;
		}
		q=q->next;
	}
	printf("\nElement not found\n");
	return 0;
}

int del(int data)
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return 0;
	}
	if(start->next==NULL)
	{
		if(start->info==data)
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return 1;
		}
		else
		{
			printf("\nElement not found\n");
			return 0;
		}
	}
		if(start->info==data)
		{
			tmp=start;
			start=start->next;
			start->prev=NULL;
			free(tmp);
			return 1;
		}
		tmp=start->next;
		while(tmp->next!=NULL)
		{
			if(tmp->info==data)
			{
				tmp->prev->next=tmp->next;
				tmp->next->prev=tmp->prev;
				free(tmp);
				return 1; 
			}
			tmp=tmp->next;
		}
		if(tmp->info==data)
		{
			tmp->prev->next=NULL;
			free(tmp);
			return 1;
		}
		
	printf("\nElement not found\n");
	return 0;
}
void create()
{
	int i,n,data;
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return;
	printf("Enter element to be inserted: ");
	scanf("%d",&data);
	addatemp(data);
	for(i=2;i<=n;i++)
	{
		printf("Enter element to be inserted: ");
		scanf("%d",&data);
		addatend(data);
	}
}

void display()
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nList is empty");
		return;
	}
	p=start;
	printf("\nList is:\n");
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	int ch,data,item,x=0;
	create();
	while(1)
	{
		printf("\n---Doubly Linked List---");
		printf("\n1.Insert at begining\n");
		printf("2.Insert at end\n");
		printf("3.Insert before\n");
		printf("4.Insert after\n");
		printf("5.Delete\n");
		printf("6.Display\n");
		printf("7.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&data);
				addatbeg(data);
				printf("%d inserted in the list\n",data);
				break;
			case 2:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&data);
				addatend(data);
				printf("%d inserted in the list\n",data);
				break;
			case 3:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter the element before which to insert: ");
				scanf("%d",&item);
				x=addbefore(data,item);
				if(x==1)
					printf("%d inserted in the list\n",data);
				break;
			case 4:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter the element after which to insert: ");
				scanf("%d",&item);
				x=addafter(data,item);
				if(x==1)
					printf("%d inserted in the list\n",data);
				break;
			case 5:
				printf("\nEnter the element to be deleted: ");
				scanf("%d",&data);
				x=del(data);
				if(x==1)
					printf("%d deleted from the list\n",data);
				break;
			case 6:
				display();
				break;
			case 7:
				exit(1);
			default:
				printf("You have entered wrong choice\n");
		}
	}
}

