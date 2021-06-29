// Create an array with even numbers and a list with odd numbers. Merge two sequences of numbers into a vector using the algorithm merge (). Display the vector.

#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

void disp_vec(vector<int> &v1)
{	cout<<"Merged Vector = \n";
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<"\t";
	cout<<endl;
}
void disp_list(list<int> &l1)
{	cout<<"List of odd nos = \n";
	list<int>::iterator p;
	for(p=l1.begin();p!=l1.end();++p)
		cout<<*p<<"\t";
	cout<<endl;
}

void disp_array(int *arr)
{
	cout<<"Array of even nos = \n";
	for(int i=0;i<4;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

int main()
{	int i=1;
	int a[4]={2,4,6,8};
	
	list<int> l(4);
	list<int>::iterator p;
	for(p=l.begin();p!=l.end();p++)
	{	
		*p=i;
		i+=2;
	}
	vector<int> v(8);
	disp_array(a);
	disp_list(l);
	merge(a,a+4,l.begin(),l.end(),v.begin());
	disp_vec(v);
}
