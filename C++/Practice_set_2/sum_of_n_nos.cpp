// Write a recursive function that computes the sum of all numbers from 1 to n, where n is given as parameter.
#include<iostream>
using namespace std;

int sum(int n)
{
	if(n==0)
		return 0;
	return(n+sum(n-1));
}

int main()
{
	int n;
	cout<<"Enter the nth term: ";
	cin>>n;
	cout<<"Sum of first "<<n<<" terms= "<<sum(n);
}
