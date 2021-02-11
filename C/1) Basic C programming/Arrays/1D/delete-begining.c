//to delete an element in the begining of an array
#include <stdio.h>

int main()
{
	int arr[100],i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		arr[i]=arr[i+1];
	}
	n--;
	
	printf("\nNew Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}


