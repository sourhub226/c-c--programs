// Assume that a bank maintains two kinds of accounts for customers, one called as savings and the other as current account. The savings account provides compound interest and withdrawal facilities but no cheque book facility. The current account provides cheque book facility but no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level a service charge is imposed.
// Create a class account that stores customer name, account number and type of account. From this derive the classes cur_acct and sav_acct to make them more specific to their requirements. Include necessary member functions in order to achieve the following tasks:
// (a) Accept the deposit from a customer and update the balance.
// (b) Display the balance.
// (c) Compute and deposit interest.
// (d) Permit withdrawal and update the balance.
// (e) Check for the minimum balance, impose penalty, necessary and update the balance.
// Do not use any constructors. Use member functions to initialize class members.


#include<iostream>
#include <cstring>
#include<string>
#define minimum 500
#define service_charge 100
#define r 0.15
using namespace std; 

class account
{
    protected:
		int ac_number;
    	char ac_type[100];
    public:
        void create(char *t)
		{
          strcpy(ac_type,t);
          cout<<endl<<ac_type<<" Account";
          cout<<"\nEnter account number : ";
          cin>>ac_number;
		}
};

class cur_acct: public account
{
	private:
		float balance;
	public:
		void deposit(float d)
		{
        	balance=d;
		}
 
		void withdraw(float w)
		{
			if(balance<w)
			cout<<"Sorry your balance is less than your withdrawal amount \n";
			else
            {
                balance-=w;
                if(balance<minimum)
				{			
					cout<<"\nYour current balance is "<<balance<<" which is less than "<<minimum<<endl;
					cout<<"Your account is discharged by Rs."<<service_charge<<endl;
					cout<<"You must store min Rs."<<minimum<<" to avoid discharge \n"<<endl;
					cout<<"Do you want to withdraw? (y/n) " ;                 
					char t;
					cin>>t;
					if(t=='n')
						balance+=w;
         		}
			}
		}		
		void display()
		{
            cout<<"\nNow balance = "<<balance<<"\n";
		}
};

class sav_acct:public account
{
    float balance;
    int d,m,y;
    public:
        void set_date(int a,int b,int c)
		{d=a;m=b;y=c;}
        void deposit(float d)
		{
        	int x,y,z;
        	cout<<"Enter today's date(dd mm yyyy) : ";
        	cin>>x>>y>>z;
        	set_date(x,y,z);
        	balance=d;
		}
 
       void withdraw(float w)
		{
			if(balance<w)
			    cout<<"Sorry your balance is less than your withdrawal amount \n";
			else
			{
			    balance-=w;
				if(balance<minimum)
			    {
					cout<<"\nYour current balance is "<<balance<<" which is less than "<<minimum<<endl;
					cout<<"Your account is discharged by Rs."<<service_charge<<endl;
					cout<<"You must store min Rs."<<minimum<<" to avoid discharge \n"<<endl;
					cout<<"Do you want to withdraw? (y/n) " ;
			        char test;
			        cin>>test;
			        if(test=='n')
			            balance+=w;
			    }
            }
		}
		void display()
		{
                cout<<"\nNow balance = "<<balance;
		}
		void interest()
		{
            int D[12]={31,28,31,30,31,30,31,31,30,31,30,31};
            int d1,y1,m1;
            cout<<"\nEnter req date (dd mm yyyy): ";
            cin>>d1>>m1>>y1;
            int iday,fday;
            iday=d;
        	fday=d1;
        	for(int i=0;i<m1;i++)
                fday+=D[i];
        	for(int i=0;i<m;i++)
                iday+=D[i];
    		int tday;
        	tday=fday-iday;
        	float ty;
        	ty=float(tday)/365+y1-y;
        	float intrst;
 		
        	intrst=ty*r*balance;
        	cout<<"\nInterest is : "<<intrst<<"\n";
        	balance+=intrst;
		}
};

int main()
{
	int ch;
	sav_acct sac;
    cur_acct cac;
    cout<<"Press 1 for Savings Acc\nPress 2 for Current Acc"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
	        sac.create("Savings");
	        float d;
	        cout<<"Enter your deposit amount : ";
	        cin>>d;
	        sac.deposit(d);
	        sac.display();
	        int t;
	        cout<<"\nPress 1 to see your interest\nPress 2 to skip\n";
	        cout<<"Enter your choice: ";
	        cin>>t;
	        if(t==1)
	        {
	        	sac.interest();
	        	sac.display();
			}
	        cout<<"\nEnter your withdrawal amount :";
	        float w;
	        cin>>w;
	        sac.withdraw(w);
	        sac.display();
	        break;
	    case 2:
	        cac.create("Current");
	        float dip;
	        cout<<"Enter your deposit amount : ";
	        cin>>dip;
	        cac.deposit(dip);
	        cac.display();
	        cout<<"\nEnter your withdrawal amount :";
	        float wit;
	        cin>>wit;
	        cac.withdraw(wit);
	        cac.display();
	        break;
	}
}
