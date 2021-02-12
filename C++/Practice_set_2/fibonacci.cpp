// Write a C++ function "fibonacci(...)" that computes the Fibonacci number corresponding to its positive integer argument, so that, for example, fibonacci(7) == 13.
#include<iostream>
using namespace std;

int fibonacci(int n)
{
	if(n==0||n==1)
		return n;
	else
		return (fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
	int n,i,k;
	cout<<"Enter the nth term: ";
	cin>>n;
	cout<<n<<"th no in fibonacci series is "<<fibonacci(n);
}
