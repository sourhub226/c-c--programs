//To find larger of 2 nos
#include <iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter 1st number:";
	cin>>a;
	cout<<"Enter 2nd number:";
	cin>>b;

	if(a>b)
		cout<<endl<<"The largest number is "<<a;
	else if(a<b)
		cout<<endl<<"The largest number is "<<b;
	else
		cout<<endl<<"Both numbers are equal";
}

