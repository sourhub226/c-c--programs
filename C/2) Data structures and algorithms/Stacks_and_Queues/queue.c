// To implement a Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int qarr[MAX];
int front=-1;
int rear=-1;

int isEmpty()
{
	if((front==rear+1)||front==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}

void insert(int item)
{
	if(isFull())
	{
		printf("Queue overflow\n");
		return;
	}
	if (front==-1)
		front=0;
	rear++;
	qarr[rear]=item;
}

int del()
{
	int item;
	if(isEmpty())
	{
		printf("Queue underflow\n");
		exit(1);
	}
	item=qarr[front];
	front++;
	return item;
}

void display()
{
	int i;
	printf("\nQueue array:\n");
	for(i=front;i<=rear;i++)
		printf("%d\t",qarr[i]);
	printf("\n\n");
}

int main()
{
	int ch,item;
	while(1)
	{
		printf("-------QUEUE-------\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the item: ");
				scanf("%d",&item);
				insert(item);
				printf("%d is inserted in the queue\n\n",item);
				break;
			case 2:
				printf("\nThe item %d is deleted\n\n",del());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(3);
				break;
			default:
				printf("You have entered an incorrect option");
		}
	}
}
