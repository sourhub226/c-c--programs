// Sorting a linked list
#include <stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;	
}*start;

void display()
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty");
		return;
	}
	
	p=start;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->link;
	}
}

void insert(int info)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=info;
	if(start==NULL)
	{
		tmp->link=start;
		start=tmp;
	}
	else
	{
		p=start;
		while(p->link!=NULL)
			p=p->link;
		tmp->link=NULL;
		p->link=tmp;
	}
}
void selection_sort()
{
	int tmp,k=1;
	struct node *p,*q,*min;
	for(p=start;p->link!=NULL;p=p->link)
	{
		min=p;
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(min->data>q->data)
				min=q;
		}
		if(p!=min)
		{
			tmp=p->data;
			p->data=min->data;
			min->data=tmp;
		}
		printf("\nPass %d: ",k++);
		display();
	}
}

void create()
{
	int i,n,info;
	printf("\nEnter no of items: ");
	scanf("%d",&n);
	start=NULL;
	
	if(n==0)
		return;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the item: ");
		scanf("%d",&info);
		insert(info);
	}
}

void bubble_sort()
{
	int tmp,k=1;
	struct node *p,*q,*end;
	for(end=NULL;end!=start->link;end=p)
	{
		for(p=start;p->link!=end;p=p->link)
		{
			q=p->link;
			if(p->data>q->data)
			{
				tmp=p->data;
				p->data=q->data;
				q->data=tmp;
			}
		}
		printf("\nPass %d: ",k++);
		display();
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("=== Sorting of single LL ===\n");
		printf("1)Selection Sort\n2)Bubble Sort\n3)Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				create();
				selection_sort();
				printf("\n\nSorted list is: \n");
				display();
				break;
			case 2:
				create();
				bubble_sort();
				printf("\n\nSorted list is: \n");
				display();
				break;
			case 3:
				exit(1);
			default:
				printf("You have entered wrong choice.\n\n");
		}
		printf("\n\n");
	}
}

