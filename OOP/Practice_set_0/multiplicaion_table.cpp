// To generate multiplication table of a no.
#include <iostream>
using namespace std;

int main()
{
	int i,n;
	cout<<"Enter the no: ";
	cin>>n;
	cout<<endl;
	for(i=1;i<=10;i++)
	{
		cout<<n<<" X "<<i<<" = "<<n*i<<endl;
	}
}
