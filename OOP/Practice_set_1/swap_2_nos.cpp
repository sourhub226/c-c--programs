// Write a program to swap the values of two variables
#include <iostream>
using namespace std;

int main()
{
	int a,b,temp;
	cout<<"Enter values of a and b: ";
	cin>>a>>b;
	temp=a;
	a=b;
	b=temp;
	cout<<"After swapping,\nthe values of a and b are "<<a<<" "<<b;
}
