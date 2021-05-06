//to insert an element at the end of an array
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
	printf("Enter the element to be inserted in the end: ");
	scanf("%d",&arr[n]);
	n++;
	
	printf("\nNew Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}

