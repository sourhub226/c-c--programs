// Create a base class called shape. Use this class to store two double type values that
// could be used to compute the area of figures. Derive two specific classes called triangle and
// rectangle from the base shape. Add to the base class, a member function get_data() to
// initialize base class data members and another member function display_area() to compute
// and display the area of figures. Make display_area() as a virtual function and redefine this
// function in the derived classes to suit their requirements.
// Using these three classes, design a program that will accept dimensions of a triangle or a
// rectangle interactively, and display the area.

#include<iostream>
using namespace std;
class shape
{
	public:
	double x,y;
	void get_data(double a,double b)
	{
		x=a;
		y=b;
	}
	virtual void display_area()
	{}
};
class triangle:public shape
{
	double area;
	void display_area();

};
class rectangle:public shape
{
	double area;
	void display_area();

};
void triangle::display_area()
{
	cout<<"\nEnter values of base and height: ";
	cin>>x>>y;
	get_data(x,y);
	area=(x*y)/2;
	cout<<"\nArea = "<<area<<" sq units";
}
void rectangle::display_area()
{
	cout<<"\nEnter values of x and y: ";
	cin>>x>>y;
	get_data(x,y);
	area=x*y;
	cout<<"\nArea = "<<area<<" sq units";
}
int main()
{
	shape *s1,*s2;
	triangle t;
	s1=&t;
	rectangle r;
	s2=&r;
	int c;

	cout<<"Press 1 to find area of triangle";
	cout<<"\nPress 2 to find area of rectangle";
	cout<<"\nEnter your choice: ";
	cin>>c;
	if(c==1)
	s1->display_area();
	else
	s2->display_area();

}
