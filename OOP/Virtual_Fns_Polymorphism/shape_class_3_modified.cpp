// Run the program above with the following modifications:
// (a) Remove the definition of display_area() from one of the derived
// classes.
// (b) In addition to the above change, declare the display_area() as
// virtual in the base class shape.


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
	//void display_area();
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
