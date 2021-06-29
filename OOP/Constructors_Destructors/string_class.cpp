// Define a class String that could work as a user-defined string type. 
// Write complete program to test your class to see that it does the following tasks:
// (a) Creates uninitialized string objects.
// (b) Creates objects with string constants.
// (c) Concatenates two strings properly.
// (d) Displays a desired string object.

#include<iostream>
#include<cstring>
using namespace std;

class String
{
	char *s;
	public:
		String()
		{
		    s = new char[0];
		    s == NULL;
		}
		String(char *v)
		{
			s = new char[strlen(v)];
			strcpy(s,v);
		}
		void display()
		{
		    if(s == NULL)
	            cout<<"NULL string ";
			cout<<s;
		}
		friend String Concate(const String & s1, const String & s2)
		{
			String s3;
			s3.s = new char [strlen(s1.s) + strlen(s2.s)];
			s3.s = strcat(s1.s,s2.s);
			return s3;
		}
		friend void copy(String &s1, const String & s2)
		{
			strcpy(s1.s, s2.s);
		}
		String(String &s1)
		{
		    s = new char[strlen(s1.s)];
		    strcpy(s, s1.s);
		}

};

int main()
{
	String s1("Sourabh");
	String s2(" Sathe");
	String s3;
	cout<<"S1 = ";
	s1.display();
	cout<<"\nS2 = ";
	s2.display();
	cout<<"\nAfter copying string s1 to s3 ";
	copy(s3,s1);
	cout<<"\nS3 = ";
	s3.display();
	cout<<"\nAfter assigning String s2 to s3";
	s3=s2;
	cout<<"\nS3 = ";
	s3.display();
	cout<<"\nConcatenating the two string s1 and s2, ";
	String s4;
	s4=Concate(s1,s2);
	cout<<"\nS4 = ";
	s4.display();
	return 0;
}
