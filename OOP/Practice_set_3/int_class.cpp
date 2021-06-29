// Create a class that imitates part of the functionality of the basic data type int. Call the class Int (note different capitalization). The only data in this class is an int variable. Include member functions to initialize an Int to 0, to initialize it to an int value, to display it (it looks just like an int), and to add two Int values.
// Write a program that exercises this class by creating one uninitialized and two initialized Int values, adding the two initialized values and placing the response in the uninitialized value, and then displaying this result.

#include <iostream>
using namespace std;

class Int
{
	int num;
	public:
		Int()
		{ num=0; }
		Int(int x)
		{ num=x; }

		void display()
		{ cout<<num<<endl; }
			
		int operator +(Int x)
		{ return(num+x.num); }
};

int main()
{
	Int a=7;
	Int b=6;
	Int c;
	c=a+b;
	c.display();
}
