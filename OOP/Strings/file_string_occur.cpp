// Write a program that reads the following texts and counts the number of times the word “it” appears in it.
// “It is new. It is singular.
// It is simple. It must succeed!”

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
	 ifstream fin("data.txt");
	 int count=0;
	 string ch;
	 string c="It";
	
	 while(fin)
	{
	  fin>>ch;
	  if(ch.compare(c)==0)
		count++;
	}
	
	 cout<<"Occurrence of \"It\" = "<<count;
	 fin.close(); 
	
	 return 0;

}
