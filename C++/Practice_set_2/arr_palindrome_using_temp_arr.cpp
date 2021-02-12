//To check if a string is palindrome or not(using a temp array)
#include <iostream>
#include <string.h>
using namespace std;

int rev(int *arr,int *temparr,int i,int j,int n)
{
	int temp,a;
	if(j<=i)
	{
		for(a=0;a<n;a++)	
			if(temparr[a]!=arr[a])
					return 1;
	}
	else
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		rev(arr,temparr,i+1,j-1,n);
	}
}

int main()
{
	int a,n,i=0,j,x=0;
	int arr[100],temparr[100];
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements:"<<endl;
	j=n-1;
	for(a=0;a<n;a++)
		{
			cin>>arr[a];
			temparr[a]=arr[a];
		}
	x=rev(arr,temparr,i,j,n);
	if(x==1)
		cout<<"not palindrome";
	else
		cout<<"palindrome";
}
