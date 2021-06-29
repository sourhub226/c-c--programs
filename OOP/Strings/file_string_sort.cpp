// Write a program that reads a list of countries in random order and displays them in alphabetical order. Use comparison operators and functions.
#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std; 

void swap(string *s1,string *s2)
{
	string tmp;
	tmp=*s1;
	*s1=*s2;
	*s2=tmp;
}
void display(string *s,int count)
{
	for(int i = 0; i<count-1; i++)
        cout<< s[i] <<endl;
}

int main()
{
	int i=0,count=0,j;
	string arr[10];
    ifstream file("country.txt");
    while(file)
    {
    	count++;
        file >> arr[i++];
    }
    cout<<"Before sorting: "<<endl;
    display(arr,count);

    for(i=0;i<count;i++)
    {
    	for(j=1;j<count;j++)
    	{
    		if(arr[j]<arr[j-1])
    			swap(arr[j],arr[j-1]);
		}
	}
    cout<<endl<<"After sorting: ";
    display(arr,count);
}
