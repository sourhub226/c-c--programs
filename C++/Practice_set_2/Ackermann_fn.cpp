// Write a recursive program to implement Ackermann Function
#include <iostream>
using namespace std;

int ackerman(int m,int n)
{
	if(m==0)
		return n+1;
	else if(m>0&&n==0)
		return ackerman(m-1,1);
	else 
		return ackerman(m-1,ackerman(m,n-1));
}

int main()
{
	int n,m;
	cout<<"Enter m and n: ";
	cin>>m>>n;
	cout<<"A("<<m<<","<<n<<") = "<<ackerman(m,n);
}
