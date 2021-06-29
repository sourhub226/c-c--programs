// Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. Another member function should display it, in 11:59:59 format. The final member function should add two objects of type time passed as arguments.
// A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized. Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable. Make appropriate member functions const.

#include <iostream>
using namespace std;

class time
{
	int hours;
	int minutes;
	int seconds;
	
	public:
		time()
		{
			hours=0;minutes=0;seconds=0;
		}	
		time(int x,int y,int z)
		{
			hours=x;minutes=y;seconds=z;
		}
		void display()
		{
			cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
		}
		time add(time t2,time t3)
		{
			hours=t2.hours+t3.hours;
			minutes=t2.minutes+t3.minutes;
			seconds=t2.seconds+t3.seconds;
			if(seconds>=60)
			{
				seconds=seconds%60;
				minutes++;
			}
			if(minutes>=60)
			{
				minutes=minutes%60;
				hours++;
			}	
		}
};

int main()
{
	time t1;
	time t2(10,57,58);
	time t3(3,20,12);
	t1.add(t2,t3);
	t1.display();
}
