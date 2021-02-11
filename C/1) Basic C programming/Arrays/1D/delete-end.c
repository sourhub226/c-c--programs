//to delete an element in the end of an array
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
	arr[n-1]=0;
	n--;
	
	printf("\nNew Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}


