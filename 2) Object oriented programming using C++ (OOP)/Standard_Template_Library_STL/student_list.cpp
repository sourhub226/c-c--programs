// Create a student class that includes student's first name and his roll number. Create five objects of these class and store them in a list thus creating a phone list. Write a program using this list to display the student name if the roll number is given and vice- versa.
#include<list>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
class student
{
	
	public: 
	int roll;
	char name[10];
		student(int r,char s[])
		{
			roll=r;
			strcpy(name,s);
		}
		void showname()
		{
			cout<<name;
		}
		int getroll()
		{
			return roll;
		}
};
int main()
{	int rno,ch;
	char nm[10];	
	student s1(123,"abc"),s2(456,"def"),s3(789,"ghi"),s4(987,"jkl"),s5(654,"mno");
	list<student>l1;
	l1.push_back(s1);
	l1.push_back(s2);
	l1.push_back(s3);
	l1.push_back(s4);
	l1.push_back(s5);
	
	while(1)
	{
		int flag=0;
		list<student>::iterator p;
		cout<<"1.Search name\n2.Search roll no.\n3.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1 :cout<<"\nEnter roll no: ";
					cin>>rno;
					for(p=l1.begin();p!=l1.end();++p)
					{
						if(p->getroll()==rno)
						{
							cout<<"Name: "<<p->name<<endl;
							flag=1;
							break;
						}	
					}
					if(flag==0)
						cout<<"Roll No. not found"<<endl;
					break;
			case 2 :cout<<"\nEnter name: ";
					cin>>nm;
					for(p=l1.begin();p!=l1.end();++p)
					{
						if(strcmp(p->name,nm)==0)
						{
							cout<<"Roll No."<<p->roll<<endl;
							flag=1;
							break;
						}
					}
					if(flag==0)
						cout<<"Name not found"<<endl;
					break;	
			case 3 :exit(1);	
		}
		cout<<endl;
	}
	return 0;
}
