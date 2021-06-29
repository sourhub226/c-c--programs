// Write a program to calculate area of circle.
#include <iostream>
using namespace std;
#define PI 3.14 

int main()
{
	float r,area;
	cout<<"Enter the radius: ";
	cin>>r;
	area=PI*r*r;
	cout<<"Area = "<<area;
}
