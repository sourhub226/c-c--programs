// Write a code segment that does the following:
// (a) Defines a vector v with a maximum size of 10.
// (b) Sets the first element of v to 0.
// (c) Sets the last element of v to 9.
// (d) Sets the other elements to 1.
// (e) Displays the contents of v.

#include<iostream> 
#include <vector>
#include <algorithm>
using namespace std; 
void display(vector<int> &v)
{
	for (int i=0; i<v.size(); i++) 
        cout<< v[i]<<"\t";
        cout<<endl;
}
int main()
{
	int i;
	vector<int> v(10);
	cout<<"Original Vector:\n";
	display(v);
	v[0]=0;
	cout<<"Vector after setting first element to 0:\n";
	display(v);
   	v[9]=9;
   	cout<<"Vector after setting last element to 9:\n";
	display(v);
	for(i=1;i<9;i++)
		v[i]=1;
	cout<<"Vector after setting all other element to 1:\n";
    display(v);
	
}
