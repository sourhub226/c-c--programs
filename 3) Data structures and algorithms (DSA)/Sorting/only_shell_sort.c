//Shell sort
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stnames[MAX][MAX]={"sourabh","hrithik","neha","pratik","prateek","rohit","rohan"};

void display(char names[][MAX],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("| %s ",names[i]);
	printf("|\n");	
}

void shellsort(int incr,int n)
{
	int i,j,k=0;
	char temp[100];
	while(incr>=1)
	{
		for(i=incr;i<n;i++)
		{	
			strcpy(temp,stnames[i]);
			
			for(j=i-incr;(j>=0 && strcmp(temp,stnames[j])<0);j=j-incr)
				strcpy(stnames[j+incr],stnames[j]);
			strcpy(stnames[j+incr],temp);
			
		}
		incr-=2;
		printf("\nPASS %d\n",++k);
		display(stnames,n);
	}
}

int main()
{	
	int n=7;
	printf("SHELL SORT\n");
	printf("Unsorted strings:\n");
	display(stnames,n);
	shellsort(5,n);
	printf("\nSorted strings:\n");
	display(stnames,n);
}
