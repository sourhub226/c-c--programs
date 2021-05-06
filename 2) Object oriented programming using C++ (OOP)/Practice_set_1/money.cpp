// Write a program which accepts amount as integer and display total number of Notes of Rs. 500, 100, 50, 20, 10, 5 and 1
#include <iostream>
using namespace std;
int main()
{
	int n, a, b, c, d, e, f,g;
	cout<<"Enter the amount in Rupees : ";
	cin>>n;
	cout<<"Rs. "<<n<<"=";
	
	if (n >= 500)
	{
		a = n / 500;
		n = n % 500;
		cout<<endl<<a<<" notes of Rs.500";
	}
	
	if (n >= 100)
	{
		b = n / 100;
		n = n % 100;
		cout<<endl<<b<<" notes of Rs.100";
	}
	
	if (n >= 50)
	{
		c = n / 50;
		n = n % 50;
		cout<<endl<<c<<" notes of Rs.50";
	}
	
	if (n >= 20)
	{
		d = n / 20;
		n = n % 20;
		cout<<endl<<d<<" notes of Rs.20";
	}
	
	if (n >= 10)
	{
		e = n / 10;
		n = n % 10;
		cout<<endl<<e<<" notes of Rs.10";
	}
	
	if (n >= 5)
	{
		f = n / 5;
		n = n % 5;
		cout<<endl<<f<<" notes of Rs.5";
	}
	
	if (n >= 1)
	{
		g = n / 1;
		n = n % 1;
		cout<<endl<<g<<" notes of Re.1";
	}
}

