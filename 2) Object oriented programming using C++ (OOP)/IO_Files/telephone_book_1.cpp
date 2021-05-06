// A file contains a list of telephone numbers in the following form
// John            23456
// Ahmed           9876
// ……………           …………
// the names contain only one word and the names and telephone numbers are separated by white
// spaces. Write program to read this file and output the list in two columns. The names should be
// left justified and the numbers should be right justified.

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std; 

int main()
{
    char name[100],n[100],number[100];
 
    ifstream file("telephone.txt");
    cout<<setw(16)<<left<<"Name"<<left<<"Number"<<endl;

	while (file>>name)
	{
		file.getline(number,100);
        cout<<setw(10)<<left<<name<<number<<endl;
	}
    return 0;
}
