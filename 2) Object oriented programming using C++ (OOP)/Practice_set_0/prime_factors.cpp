// To calc prime factors of a no.
#include <iostream> 
using namespace std; 

int main()
{
	int n,i;
	int arr[]={2,3,5,7,11,13,17,19,23,29};
	cout<<"Enter a no: ";
	cin>>n;
	cout<<"Prime Factors: "<<endl;
	for(i=0;i<=n;i++)
	{
		while(1)
		{
			if(n%arr[i]==0)
			{
					cout<<arr[i]<<"\t";
					n=n/arr[i];	
			}
			else
				break;
		}
	}
}
