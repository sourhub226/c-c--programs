//to separate +ve and -ve elements into 2 separate arrays
#include <stdio.h>

int main()
{
	int arr[100],pos[100],neg[100],i,n,a=0,b=0;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			pos[a]=arr[i];
			a++;
		}
		else if(arr[i]<0)
		{
			neg[b]=arr[i];
			b++;
		}
	}
	printf("\nArray of positive nos:\n");
	for(i=0;i<a;i++)
	{
		printf("%d\t",pos[i]);
	}
	printf("\nArray of negative nos:\n");
	for(i=0;i<b;i++)
	{
		printf("%d\t",neg[i]);
	}
} 
