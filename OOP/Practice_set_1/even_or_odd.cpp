//Write a program to check whether the given number is even or odd (using ? : ternary operator )
#include <iostream>
using namespace std;

int main()
{
	int a;
	cout<<"Enter the no: ";
	cin>>a;
	a%2==0? cout<<"The no is even":cout<<"The no is odd";
}
