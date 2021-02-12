//to find largest and smallest element in a 1-D array
#include <stdio.h>

int main()
{
	int arr[100],i,n,l,s;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	l=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]>l)
			l=arr[i];
	}
	printf("\nLargest element = %d\n",l);
	
	s=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]<s)
			s=arr[i];
	}
	printf("Smallest element = %d",s);
}
