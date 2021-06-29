// An educational institution wishes to maintain a database of its employees. The database is divided into a number of classes whose hierarchical relationships are shown in following figure. The figure also shows the minimum information required for each class. Specify all classes and define functions to create the database and retrieve individual information as and when required.

// staff (code,name) -> teacher (subject,publication) 
// staff (code,name) -> typist (speed)
// staff (code,name) -> officer (grade)
// typist (speed) -> regular
// typist (speed) -> casual (daily_wages)

#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std; 
class staff
{
    public:
    	int code;
		char name[100];
        void set_info(char *n,int c)
        {
            strcpy(name,n);
            code=c;
        }
};
 
class teacher : public staff
{
	protected:
    	char sub[100];
		char publication[100];
    public:
        void set_details()
        {
			cout<<"\tEnter subject: ";
			cin>>sub;
			cout<<"\tEnter publication: ";
			cin>>publication;
        }
        void show()
        {
            cout<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Code"<<setw(15)<<left<<"Subject"<<setw(15)<<left<<"Publication"<<endl;
			cout<<setw(15)<<left<<name<<setw(15)<<left<<code<<setw(15)<<left<<sub<<setw(15)<<left<<publication<<endl;
        }
};
 
class officer:public staff
{
    char grade[100];
    public:
        void set_details()
        {
            cout<<"\tEnter grade: ";
            cin>>grade;
    	}
 
        void show()
        {
            cout<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Code"<<setw(15)<<left<<"Grade"<<endl;
			cout<<setw(15)<<left<<name<<setw(15)<<left<<code<<setw(15)<<left<<grade<<endl;
        }
};

class typist: public staff
{
    protected:
        float speed;
    public:
        void set_speed()
        {
            cout<<"\tEnter typing speed (words/min): ";
            cin>>speed;
        }
};

class regular:public typist
{
    protected:
    	float wage;
    public:
    	void set_wage()
		{
			cout<<"\tEnter daily wages: ";
			cin>>wage;
		}
       void show()
        {
            cout<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Code"<<setw(15)<<left<<"Speed"<<setw(15)<<left<<"Daily Wages"<<endl;
			cout<<setw(15)<<left<<name<<setw(15)<<left<<code<<setw(15)<<left<<speed<<setw(15)<<left<<wage<<endl;
        }
};

class causal:public typist
{
    float wage;
    public:
        void set_wage()
		{
			cout<<"\tEnter daily wages: ";
	   		cin>>wage;
		}
        void show()
        {
            cout<<setw(15)<<left<<"Name"<<setw(15)<<left<<"Code"<<setw(15)<<left<<"Speed"<<setw(15)<<left<<"Daily Wages"<<endl;
			cout<<setw(15)<<left<<name<<setw(15)<<left<<code<<setw(15)<<left<<speed<<setw(15)<<left<<wage<<endl;
        }
 
};
 
int main()
{
	int code;
	char name[20];
    teacher t;
    cout<<"Enter teacher's name and code: ";
    cin>>name>>code; 
    t.set_info(name,code);
    t.set_details();
 
    officer o;
    cout<<"Enter officer's name and code: ";
    cin>>name>>code; 
    o.set_info(name,code);
    o.set_details();
 
    regular rt;
    cout<<"Enter regular typist's name and code: ";
    cin>>name>>code; 
    rt.set_info(name,code);
    rt.set_speed();
    rt.set_wage();
 
	causal ct;
    cout<<"Enter casual typist's name and code: ";
    cin>>name>>code; 
	ct.set_info(name,code);
	ct.set_speed();
	ct.set_wage();

	cout<<"\nSTAFF DATABASE\n";
        cout<<"About teacher: "<<endl;
        t.show();
        cout<<"About officer: "<<endl;
    	o.show();
        cout<<"About regular typist : "<<endl;
        rt.show();
        cout<<"About causal typist : "<<endl;
        ct.show();
 
    return 0;
}
