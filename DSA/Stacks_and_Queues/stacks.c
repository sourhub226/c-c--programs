// To implement a Stack
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stackarr[MAX];
int top =-1;

int isFull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stackarr[top];
}

void push(int item)
{
	if(isFull())
	{
		printf("Stack Overflow\n");
	}
	else
	{
		top++;
		stackarr[top]=item;
	}
}

int pop()
{
	int item;
	if(top==-1)
	{
		printf("Stack underflow\n");
		exit(2);
	}
	else
	{
		item=stackarr[top];
		top--;
		return item;
	}
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("Stack is empty\n");
		exit(1);
	}
	printf("\nStack contents:\n");
	for(i=top;i>=0;i--)
		printf("|\t%d\t|\n",stackarr[i]);
}

int main()
{
	int ch,item;
	while(1)
	{
		printf("-------STACK-------\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the item: ");
				scanf("%d",&item);
				push(item);
				printf("%d is pushed in the stack\n",item);
				break;
			case 2:
				printf("\nThe item %d is popped out\n",pop());
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nThe top element is %d\n",peek());
				break;
			case 5:
				exit(3);
				break;
			default:
				printf("You have entered an incorrect option");
		}
	}
}