// Write a recursive function that determines whether an array is a palindrome, where the array and its size are given as parameters.
#include <iostream>
using namespace std;

int rev(int *arr,int n)
{
	static int a=0;
	if(a>=n)
		return 0;
	else
	{
		if(arr[a++]!=arr[n-1])
			return 1;
		rev(arr,n-1);
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
	x=rev(arr,n);
	if(x==1)
		cout<<"Not palindrome";
	else
		cout<<"Palindrome";
}
