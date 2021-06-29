//selection sort in descending order
#include <stdio.h>

int main()
{
	int max,i,n,temp,j,arr[100];
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]>arr[max])
				max=j;
		}
		if(i!=max)
		{
			temp=arr[i];
			arr[i]=arr[max];
			arr[max]=temp;
		}
	}	
	
	printf("Sorted Array (descending):\n");	
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	
}
