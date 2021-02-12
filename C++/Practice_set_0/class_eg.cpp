// Basic cppp programs on class
#include <iostream>
using namespace std;

class human
{
	private:
		string name;
	public:
		human()
		{
			name="Sourabh";
			cout<<"constr "<<name<<endl;
		}
	void display()
	{
		cout<<"disp "<<name<<endl;
	}
};

int main()
{
	human sourabh;
	sourabh.display();
}
