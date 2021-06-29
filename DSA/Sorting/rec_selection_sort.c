//recursive selection sort
#include <stdio.h>
int rselection(int arr[],int n,int i)
{
	int j,min=i,temp;
	for(j=i+1;j<n;j++)
	{
		if(arr[j]<arr[min])
			min=j;
	}	
	temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;
	
	if(i+1<n)
		rselection(arr,n,i+1);
}
int main()
{
	int i,n,arr[100];
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	rselection(arr,n,0);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}
