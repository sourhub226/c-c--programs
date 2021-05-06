// Swapping without using temp var
#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter the values of a and b: ";
	cin>>a>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<endl;
	cout<<"After swapping,"<<endl<<"The values of a and b are "<<a<<" & "<<b;
}

