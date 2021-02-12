// Write a program which accepts days as integer and display total number of years, months and days in it.
#include <iostream>
using namespace std;

int main()
{
	int days,d,m,y;
	cout<<"Enter total no of days: ";
	cin>>days;
	y=days/365;
	m=(days%365)/30;
	d=days-m*30-y*365;
	
	cout<<y<<" years "<<m<<" months "<<d<<" days ";
}
