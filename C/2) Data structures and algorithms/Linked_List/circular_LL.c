// Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int info;
	struct node *link;
}*last;

void addatbeg(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
}
void addatemp(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
}

void addatend(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
}

int addafter(int data,int item)
{
	struct node *tmp,*p;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
					return 1;
		}
		p=p->link;	
	}while(p!=last->link);
		printf("\nElement not found\n");
		return 0;
}

void display()
{
	struct node *p;
	if(last==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	p=last->link;
	printf("\nList is:\n");
	do
	{
		printf("%d\t",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}

void create()
{
	int i,n,data;
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	last=NULL;
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

int del(int data)
{
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("\nList is empty\n");
		return 0;
	}
	if(last->link==last&&last->info==data)
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return 1;
	}
		if(last->link->info==data)
		{
			tmp=last->link;
			last->link=tmp->link;
			free(tmp);
			return 1;
		}
		p=last->link;
		while(p->link!=last)
		{
			if(p->link->info==data)
			{
				tmp=p->link;
				p->link=tmp->link;
				free(tmp);
				return 1;
			}
			p=p->link;
		}
		if(last->info==data)
		{
			tmp=last;
			p->link=last->link;
			last=p;
			free(tmp);
			return 1;
		}
		printf("\nElement not found\n");
		return 0;
}

int main()
{
	int ch,data,item,x=0;
	create();
	while(1)
	{
		printf("\n--Circular Linked List--\n");
		printf("1.Insert at begining\n");
		printf("2.Insert at end\n");
		printf("3.Insert after\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Exit\n");
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
				printf("\nEnter the element after which to insert: ");
				scanf("%d",&item);
				x=addafter(data,item);
				if(x==1)
					printf("%d inserted in the list\n",data);
				break;
			case 4:
				printf("\nEnter the element to be deleted: ");
				scanf("%d",&data);
				x=del(data);
				if(x==1)
					printf("%d deleted from the list\n",data);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
			default:
				printf("You have entered wrong choice\n");
		}
	}
}


