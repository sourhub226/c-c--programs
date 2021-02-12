// Write a program to swap value of two variables without using third variable.
#include <iostream>
using namespace std;

int main()
{
	int a,b,temp;
	cout<<"Enter values of a and b: ";
	cin>>a>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"After swapping,\nthe values of a and b are "<<a<<","<<b;
}
