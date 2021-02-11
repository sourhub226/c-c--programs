//to find largest element in a 1-D array using pointers
#include <stdio.h>

int main()
{
	int arr[100],i,n,l,*p;
	p=arr;
	printf("Enter the size of the array: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	l=*p;
	for(i=0;i<n;i++)
	{
		if(*p>l)
			l=*p;
		p++;
	}
	printf("\nLargest element = %d\n",l);
}
