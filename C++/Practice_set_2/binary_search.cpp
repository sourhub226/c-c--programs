// Write a recursive functions “int binary_search( );” that performs binary search on an array.
#include<iostream>
using namespace std;

int rbinsrch(int a[],int item,int low,int up)
{
	int mid;
	if(low>up)
		return -1;
	mid=(low+up)/2;
	if(a[mid]<item)
		rbinsrch(a,item,mid+1,up);
	else if(a[mid]>item)
		rbinsrch(a,item,low,mid-1);
	else 
		return mid;
}

int main()
{
	int i,n,item,pos;
	int a[100];
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements of the array in sorted order: "<<endl;
	for (i=0;i<n;i++)
		cin>>a[i];

	cout<<endl<<"Enter the element to be searched: ";
	cin>>item;
	pos=rbinsrch(a,item,0,n-1);
	if(pos==-1)
		cout<<"Element not found";
	else	
		cout<<"The element is found at location "<<pos+1;
}
