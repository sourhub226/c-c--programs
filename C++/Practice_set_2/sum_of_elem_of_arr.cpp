// Write a recursive function that computes and returns the sum of all elements in an array, where the array and its size are given as parameters.
#include <iostream>
using namespace std;

int add(int *arr,int n)
{
	static int sum=0;
	if(n==0)
		return sum;
	else
	{
		sum=sum+arr[n-1];	
		add(arr,n-1);	
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
	cout<<"Sum of elements of the array is "<<add(arr,n);
}
