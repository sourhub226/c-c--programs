// Design a class Polar which describes a point in the plane using polar coordinates radius and angle.
// Use the overloaded + Operator to add two objects of Polar.
#include<iostream>
#include<math.h>
using namespace std;

class polar
{
	double a,r,x,y;

public:
	polar()
	{
		a = 0;
		r = 0;
		convert();
	}
	polar (double rad, double ang)
	{
		a = ang;
		r = rad;
		convert();
	}
	polar operator+(polar);
	void convert(void);
	void display(void);
};

void polar:: convert(void)
{
	x = r*cos(a*3.14159/180);
	y = r*sin(a*3.14159/180);
}

polar polar:: operator+ (polar p)
{
	polar temp;
	temp.x = x + p.x;
	temp.y = y + p.y;
	temp.a = atan(temp.y/temp.x)*180/3.14159;
	temp.r = sqrt(temp.x*temp.x + temp.y*temp.y);
	return temp;
}

void polar:: display(void)
{
	cout<<"r = "<<r<<", a = "<<a<<"\n";
}

int main()
{
	polar p1(3,30);
	polar p2(4,45);
	polar p3 = p1 + p2;

	p1.display();
	p2.display();
	p3.display();
	return(0);
}
