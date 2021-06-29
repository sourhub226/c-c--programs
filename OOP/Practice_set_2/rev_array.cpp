// To perform in-place reverse of an array
#include <iostream>
using namespace std;

int rev(int *arr,int i,int j,int n)
{
	int temp,a;
	if(j<=i)
		for(a=0;a<n;a++)
			cout<<arr[a];
	else
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		rev(arr,i+1,j-1,n);
	}
	
}

int main()
{
	int a,n,i=0,j;
	int arr[100];
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements:"<<endl;
	j=n-1;
	for(a=0;a<n;a++)
		cin>>arr[a];
	rev(arr,i,j,n);
}
