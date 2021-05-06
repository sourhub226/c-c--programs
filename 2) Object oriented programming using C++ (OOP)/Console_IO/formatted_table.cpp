// Write a program to read a list containing item name, item code, and cost interactively
// and produce a three-column output as shown below.
// Name                Code                  Cost
// Turbo C++           1001                  250.95
// C primer            905                   95.70
// ………………              …………                  ……………
// ………………              …………                  ……………

#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class item
{
	char name[40];
	int code;
	float cost;
	public:
		void get_data(char *n,int c,float co)
		{
			strcpy(name,n);
			code=c;
			cost=co;
		}
		void display();
};

void item:: display()
{
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	cout.setf(ios::showpoint);
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(40)<<name<<code;
	cout.setf(ios::right,ios::adjustfield);
	cout<<setw(15)<<cost<<endl;
}

int main()
{
	item a[4];
	a[0].get_data("Turbo C++",1001,250.95);
	a[1].get_data("C primer",9035,95.7);
	a[2].get_data("Intro to GitHub",2654,9.459);
	a[3].get_data("Object oriented programming",8879,145.00);
	cout<<setw(10)<<"Name"<<setw(34)<<"Code"<<setw(15)<<"Cost"<<endl;
	for(int i=0;i<60;i++)
		cout<<"-";
	cout<<endl;
	for(int i=0;i<4;i++)
		a[i].display();
}
