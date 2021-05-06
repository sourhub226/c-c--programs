// To increment every element in the array by 2 
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
	for(i=0;i<n;i++)
	{
		arr[i]=arr[i]+2;
	}

	printf("\nNew Incremented Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
