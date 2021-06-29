// Write a program to implement quick sort recursively.
#include <iostream>
using namespace std;

int partition(int *a,int low,int up)
{
    int pivot=a[up];
    int pval=low;
    int i,temp; 
    
    for(i=low;i<up;i++)
    {
    	if(a[i]<=pivot)
        {
            temp=a[i];
            a[i]=a[pval];
            a[pval]=temp;
            pval++;
        }
    }
    temp=a[up];
    a[up]=a[pval];
    a[pval]=temp;
    
    return pval;
}
void quicksort(int *a,int low,int up)
 {
    if(low<up)
    {
        int pval=partition(a,low,up);
        quicksort(a,low,pval-1);
        quicksort(a,pval+1,up);
    }
}
int main()
{
	int a[100],n;
    cout<<"Enter number of elements of array: ";
    cin>>n;   
    cout<<"Enter "<<n<<" elements of the array"<<endl;
    for(int i=0;i<n;i++)
    	cin>>a[i];
	cout<<"Unsorted array:"<<endl;
	for(int i=0;i<n;i++)
    	cout<<a[i]<<"\t";
    quicksort(a,0,n-1);
    cout<<endl<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    	cout<<a[i]<<"\t";
}
