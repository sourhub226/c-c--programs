//to search for an element in the array
#include <stdio.h>

int main()
{
	int arr[100],i,n,a,flag=0;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to be searched: ");
	scanf("%d",&a);
	for(i=0;i<n;i++)
	{
		if (arr[i]==a)
			{
				flag=1;
				printf("The element %d is at position %d\n",a,i+1);
			}
	}
	if (flag==0)
		printf("Element not found");
}
