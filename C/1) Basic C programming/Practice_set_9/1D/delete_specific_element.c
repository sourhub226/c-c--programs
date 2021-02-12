//to delete a specific element in an array
#include <stdio.h>

int main()
{
	int arr[100],i,n,j,a;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to be deleted: ");
	scanf("%d",&a);
	
	for(i=0;i<n;i++)
	{
		if (arr[i]==a)
			for(j=i+1;j<n;j++)
				arr[j-1]=arr[j];
	}
	n--;
	
	printf("\nNew Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
