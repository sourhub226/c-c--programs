//Selection sort
#include<stdio.h>
#define MAX 100
int nos[]={82,42,49,8,25,52,36,93,59};

void display(int num[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("| %d ",num[i]);
	printf("|\n");	
}
 
int selectionsort(int a[],int n)
{
	int min,i,temp,j,k=0;
	for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
        printf("\nPASS %d\n",++k);
        display(nos,n);
    }
}
int main()
{
    int n=9;
    printf("SELECTION SORT\n");
	printf("Unsorted nos:\n");
	display(nos,n);
	selectionsort(nos,n);
	printf("\nSorted nos:\n");
	display(nos,n);        
}