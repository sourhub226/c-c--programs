//Shell sort, Merge sort and Quick sort
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(char a[][20],int n)
{
	int i;
	printf("| ");
	for(i=0;i<n;i++)
		printf("%s | ",a[i]);
	printf("\n");
}
void shell_sort(char s1[][20],int n)
{
	int inc=3,i,j;
	char temp[10];
	printf("\nUnsorted array : ");
	display(s1,n);
	
	while(inc>=1)
	{
		for(i=inc;i<n;i++)
		{
			strcpy(temp,s1[i]);
			for(j=i-inc;(j>=0&&strcmp(temp,s1[j])<0);j=j-inc)
				strcpy(s1[j+inc],s1[j]);
			strcpy(s1[j+inc],temp);
		}
		inc=inc-2;
	}
	printf("Sorted array : ");
	display(s1,n);
	printf("\n");
}
void copy(char a[][20],char temp[][20],int low,int high)
{
	int i;
	for(i=low;i<=high;i++)
		strcpy(a[i],temp[i]);
}
void merge(char a[][20],char temp[][20],int low1,int high1,int low2,int high2)
{
	int i=low1;
	int j=low2;
	int k=low1;
	while((i<=high1) && (j<=high2))
	{
		if(strcmp(a[i],a[j])<=0)
			strcpy(temp[k++],a[i++]);	
		else
			strcpy(temp[k++],a[j++]);	
	}
	while(i<=high1)
		strcpy(temp[k++],a[i++]);
	while(j<=high2)
		strcpy(temp[k++],a[j++]);
}
void merge_pass(char a[][20],char temp[][20],int size,int n)
{
	int i,low1,low2,high1,high2;
	low1=0;
	while(low1+size<n)
	{
		high1=low1+size-1;
		low2=low1+size;
		high2=low2+size-1;
		if(high2>=n)
			high2=n-1;
		merge(a,temp,low1,high1,low2,high2);
		low1=high2+1;
	}
	for(i=low1;i<=n-1;i++)
		strcpy(temp[i],a[i]);
	copy(a,temp,0,n);	
}
void merge_sort(char a[][20],int n)
{
	char temp[5][20];
	int size=1;
	while(size<n)
	{
		merge_pass(a,temp,size,n);
		size=size*2;
	}
}

void rmerge_sort(char a[][20],int low,int high)
{	int mid;
	char temp[3][20];
	if(low<high)
	{
		mid=(low+high)/2;
		rmerge_sort(a,low,mid);
		rmerge_sort(a,mid+1,high);
		merge(a,temp,low,mid,mid+1,high);
		copy(a,temp,low,high);
	}
}
void quick_sort(char a[][20],int low,int high)
{	
	int pivposn;
	if(low>=high)
		return;
	pivposn=partition(a,low,high);
	quick_sort(a,low,pivposn-1);
	quick_sort(a,pivposn+1,high);	
}
int partition(char arr[][20],int low,int high)
{
	int i,j;
	char temp[10],pivot[10];
	i=low+1;
	j=high;
	strcpy(pivot,arr[low]);
	while(i<=j)
	{
		while(strcmp(arr[i],pivot)<0 && (i<high))
			i++;
		while(strcmp(arr[j],pivot)>0)
			j--;
		if(i<j)
		{
			strcpy(temp,arr[i]);strcpy(arr[i],arr[j]);strcpy(arr[j],temp);
			i++;j--;
		}
		else
			i++;		
	}
	strcpy(arr[low],arr[j]);strcpy(arr[j],pivot);
	return j;
}

int main()
{
	int i,j,ch,m,n;
	char s1[20][20]={"mno","def","abc","ghi","rst"};					//static allocation , static declaration
	char s2[20][20];
	char s3[20][20]; 												// recursive merge sort static allocation
	char s4[20][20]={"wxy","abc","mno","jkl","rst"};
	while(1)
	{
		
		printf("1.Shell Sort\n2.Recursive Merge Sort\n3.Iterative Merge Sort\n4.Quick sort\n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: shell_sort(s1,5); 									//shell sort
					break;
			case 2:	printf("\nEnter no of elements: ");
					scanf("%d",&n);
					printf("Enter %d elements: ",n);
					for(i=0;i<n;i++)									//dynamic declaration
						scanf("%s",s3[i]);
					printf("\nUnsorted array : ");
					display(s3,n);
					rmerge_sort(s3,0,n-1);								//Recursive merge sort
					printf("Sorted array : ");
					display(s3,n);
					printf("\n");	
					break;
			case 3: for(i=0;i<5;i++)
						s4[i]==(char*)malloc(sizeof(char));			//dynamic allocation
					printf("\nUnsorted array : ");
					display(s4,5);
					merge_sort(s4,5);
					printf("Sorted array : ");
					display(s4,5);
					printf("\n");	
					break;		
			case 4: printf("\nEnter no of elements: ");
					scanf("%d",&m);
					printf("Enter %d elements: ",m);
					for(i=0;i<m;i++)
					{
						s2[i]==(char*)malloc(sizeof(char));			//dynamic allocation
						scanf("%s",s2[i]);								//dynamic declaration
					}
					printf("\nUnsorted array : ");
					display(s2,m);
					quick_sort(s2,0,m-1);								//Quick Sort
					printf("Sorted array : ");
					display(s2,m);
					printf("\n");		
					break;
			case 5: exit(1);
			default:printf("You have entered an incorrect option\n\n");
		}
	}
}
