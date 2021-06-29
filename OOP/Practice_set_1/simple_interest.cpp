// Write a program which accept principle, rate and time from user and print the simple interest.
#include <iostream>
using namespace std;

int main()
{
	float p,r,t,si;
	cout<<"Enter principle, rate, time: ";
	cin>>p>>r>>t;
	si=(p*r*t)/100;
	cout<<"SI: "<<si;	
}
