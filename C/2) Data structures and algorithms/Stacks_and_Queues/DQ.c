//Deque
#include<stdio.h>
#include<stdlib.h>
#define MAX 7
int deque_arr[MAX];
int front=-1;
int rear=-1;
void insert_frontend(int item);
void insert_rearend(int item);
int delete_Frontend();
int delete_Rearend();
void display();
int isEMPTY();
int isFULL();

int isEMPTY()
{
	if(front==-1)
	    return 1;
	else
	    return 0;
}
int isFULL()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
	    return 0;
}
void insert_frontend(int item)
{
	if(isFULL())
	{
		printf("Deque overflow\n");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(front==0)
	    front=MAX-1;
	else 
	    front=front-1;
    deque_arr[front]=item;
}
void insert_rearend(int item)
{
	if(isFULL())
	{
		printf("Deque overflow\n");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==MAX-1)
	    rear=0;
	else
        rear=rear+1;
   deque_arr[rear]=item;	
}
int delete_Frontend()
{
	int item;
	if(isEMPTY())
	{
		printf("Deque underflow\n");
		exit(1);
	}
	item=deque_arr[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
	    front=0;
	else
	    front=front+1;
	return item;
}
int delete_Rearend()
{
	int item;
	if(isEMPTY())
	{
		printf("Deque underflow\n");
		exit(1);
	}
	item=deque_arr[rear];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
	    rear=MAX-1;
	else
	    rear=rear-1;
	return item;
}
void display()
{
	
	int i;
	if(isEMPTY())
	{
		printf("Deque underflow\n");
		return;
	}
	printf("\nDeque elements :\n");
	i=front;
	if(front<=rear)
	{
		while(i<=rear)
		printf("%d ", deque_arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
		     printf("%d ", deque_arr[i++]);
	    i=0;
	    while(i<=rear)
	        printf("%d ", deque_arr[i++]);
	}
	
	printf("\n");
}

int main()
{
	int choice,item;
	while(1)
	{
		printf("-------DEQUE-------\n");
		printf("1.Insert at front end\n");
		printf("2.Insert at rear end\n");
		printf("3.Delete from front end\n");
		printf("4.Delete from rear end\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&item);
				insert_frontend(item);
				printf("%d inserted\n",item);
				break;
			case 2:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&item);
				insert_rearend(item);
				printf("%d inserted\n",item);
				break;
			case 3:
				printf("%d is deleted\n",delete_Frontend());
				break;
			case 4:
				printf("%d is deleted\n", delete_Rearend());
				break;
			case 5:
				display();
				
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("You have entered an incorrect option");
		}	
		printf("front=%d\trear=%d\n\n", front,rear);
	}
}

