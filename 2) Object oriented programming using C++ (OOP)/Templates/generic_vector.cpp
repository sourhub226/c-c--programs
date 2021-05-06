// Write a class template to represent a generic vector. Include member functions to
// perform the following tasks:
// (a) To create the vector
// (b) To modify the value of a given element
// (c) To multiply by a scalar value
// (d) To display the vector in the following form (10, 20, 30 …)

#include<iostream>
#include<iomanip>
using namespace std;

template <class T>
class vector
{
	float *p;
	int size;
	public:
		void creat_vector(T a);
		void set_element(int i,T value);
		void modify(void);
		void multiply(T b);
		void display(void);
};

template <class T>
void vector<T>::creat_vector(T a)
{
	size=a;
	p=new float[size];
}

template <class T>
void vector<T>::set_element(int i,T value)
{
	p[i]=value;
}

template <class T>
void vector<T> :: multiply(T b)
{
	for(int i=0;i<size;i++)
	p[i]=b*p[i];
}

template <class T>
void vector<T>:: display(void)
{
	cout<<"p["<<size<<"] = (";
	for(int i=0;i<size;i++)
	{
		if(i==size-1)
			cout<<p[i];
		else
			cout<<p[i]<<" , ";
	}
	cout<<")"<<endl;
}

template <class T>
void vector<T>::modify(void)
{
	int i;
	cout<<"Enter position of the element to modify it : ";
	cin>>i;
	i--;
	cout<<"Enter new value of "<<i+1<<"th element : ";
	T v;
	cin>>v;
	p[i]=v;
	cout<<"New contents : "<<endl;
	display();
	cout<<"Enter position of the element to delete it :";
	cin>>i;
	i--;
	for(int j=i;j<size;j++)
	{
		p[j]=p[j+1];
	}
	size--;
	cout<<"New contents : "<<endl;
	display();
}

int main()
{
	vector<float> obj;
	int s;
	cout<<"Enter size of vector : ";
	cin>>s;
	obj.creat_vector(s);
	cout<<"Enter "<<s<<" elements :"<<endl;
	for(int i=0;i<s;i++)
	{
		float v;
		cin>>v;
		obj.set_element(i,v);
	}
	cout<<endl<<"Contents :"<<endl;
	obj.display();
	cout<<"Enter the scalar quantity to be multiplied : ";
	float m;
	cin>>m;
	obj.multiply(m);
	cout<<"New contents : "<<endl;
	obj.display();
	obj.modify();
}
