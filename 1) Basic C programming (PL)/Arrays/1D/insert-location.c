//to insert an element at a specified position of an array
#include <stdio.h>

int main()
{
	int arr[100],i,n,a,b;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be inserted and its position: ");
	scanf("%d %d",&a,&b);
	
	for(i=n;i>=b;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[b-1]=a;
	n++;
	
	printf("\nNew Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}


