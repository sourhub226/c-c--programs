// Extend the above program to display the area of circles. This requires addition of a
// new derived class ‘circle’ that computes the area of a circle. Remember, for a circle we need
// only one value, its radius, but the get_data() function in base class requires two values to be
// passed.(Hint: Make the second argument of get_data() function as a default one with zero
// value.)

#include<iostream>
using namespace std;
class shape
{
	public:
	double x,y;
	void get_data(double a,double b=0)
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
class circle:public shape
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
void circle::display_area()
{
	cout<<"\nEnter the value of radius: ";
	cin>>x;
	get_data(x);
	area=3.14*x*x;
	cout<<"\nArea = "<<area<<" sq units";
}
int main()
{
	shape *s1,*s2,*s3;
	triangle t;
	rectangle r;
	circle c;
	int ch;
	cout<<"Press 1 to find area of triangle";
	cout<<"\nPress 2 to find area of rectangle";
	cout<<"\nPress 3 to find area of circle";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	s1=&t;
	s2=&r;
	s3=&c;
	if(ch==1)
	s1->display_area();
	else if(ch==2)
	s2->display_area();
	else
	s3->display_area();
}
