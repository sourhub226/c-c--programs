// Write a program which accept temperature in Fahrenheit and print it in centigrade.

#include <iostream>
using namespace std;

int main()
{
	float c,f;
	cout<<"Enter the temperature in fahrenheit: ";
	cin>>f;
	c=(5*(f-32))/9;
	cout<<"Temperature in celcius: "<<c;
}
