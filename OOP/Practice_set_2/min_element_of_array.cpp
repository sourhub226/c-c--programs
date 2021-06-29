// Write a recursive function that finds and returns the minimum element in an array, where the array and its size are given as parameters.
#include <iostream>
using namespace std;

int min(int arr[],int n)
{
	if(n==0)
		return arr[0];
	else
	{
		if(arr[n-1]<arr[0])
			arr[0]=arr[n-1];
		min(arr,n-1);	
	}
}

int main()
{
	int a,n,i=0,j,x=0;
	int arr[100];
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements:"<<endl;

	for(a=0;a<n;a++)
			cin>>arr[a];
	x=min(arr,n);
	cout<<"The minimum element of the array is "<<x;
}
