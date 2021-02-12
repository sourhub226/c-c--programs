// To increment every element in the matrix
#include <iostream>
using namespace std;
int main()
{
	int a[100][100],i,j,r,c;
	cout<<"Enter the rows and columns: ";
	cin>>r>>c;
	cout<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"Enter element a"<<i+1<<j+1<<": ";
			cin>>a[i][j];
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			a[i][j]=a[i][j]+1;
		}
	}
	cout<<endl<<"Resultant Matrix:"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}

}

