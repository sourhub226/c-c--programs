//to find sum and avg of marks in an arrays
#include <stdio.h>

int main()
{
	int arr[100],i,n;
	float sum=0,avg;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter marks of student %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	avg=sum/n;
	printf("\nSum = %.0f\nAvg = %f",sum,avg);
}
