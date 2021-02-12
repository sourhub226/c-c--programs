// Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cqueue_arr[MAX];
int front =-1;
int rear =-1;
void insert(int n);
int del();
void display();
int isfull();
int isempty();
int peek();

int isempty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if((front == 0 && rear == MAX-1) || front == rear+1)
		return 1;
	else
		return 0;
}
void insert(int n)
{
	if(isfull())
	{
		printf("Circular queue overflow\n");
		return;
	}
	if(front== -1)
		front = 0;
	if(rear == MAX-1)
		rear = 0;
	else
		rear = rear+1;
	cqueue_arr[rear]=n;
}
int del()
{
	int temp;
	if(isempty())
	{
		printf("Circular queue uderflow\n");
		exit(1);
	}
	temp= cqueue_arr[front];
	if(front == rear)
	{
		front =-1;
		rear =-1;
	}
	else if(front == MAX-1)
		front =0;
	else
		front = front+1;
	return temp;
}
int peek()
{
	if(isempty())
	{
		printf("Circular queue uderflow\n");
		exit(1);
	}
	return cqueue_arr[front];
}
void display()
{
	int i;
	if(isempty())
	{
		printf("Circular queue empty\n");
		return;
	}
	printf("Queue elements: \n");
	i=front;
	if(front<=rear)
	{
		while(i<=rear)
		printf("%d ",cqueue_arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",cqueue_arr[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",cqueue_arr[i++]);
	}
	printf("\n");
}
int main()
{
	int choice, item;
	while(1)
	{
		printf("-------CIRCULAR QUEUE-------\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display first element\n");
		printf("4.Display all elements\n");
		printf("5.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted: ");
				scanf("%d",&item);
				printf("%d inserted \n",item);
				insert(item);
				
				break;
			case 2:
				item=del();
				printf("%d is deleted\n",item);
				break;
			case 3:
				printf("The first element is %d\n",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("You have entered an incorrect option");
		}
		printf("front=%d\trear=%d\n\n", front,rear);
	}
}

