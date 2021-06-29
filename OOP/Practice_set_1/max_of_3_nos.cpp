// Write a program which input three numbers and display the largest number using ternary operator.
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,max;
	cout<<"Enter 3 nos: ";
	cin>>a>>b>>c;
	max=a>b? (a>c? a:c):(b>c? b:c);
	cout<<"The largest no is "<<max;
}
