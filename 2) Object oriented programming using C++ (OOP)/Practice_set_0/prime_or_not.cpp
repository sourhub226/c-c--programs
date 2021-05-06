// To check if a no is prime or not
#include <iostream>
using namespace std;

int prime(int);
int main()
{
	int n,a;
	cout<<"Enter a no: ";
	cin>>n;
	a=prime(n);
	if(a==0)
		cout<<n<<" is a prime no.";
	else
		cout<<n<<" is not a prime no.";

}

int prime(int n)
{
	int flag=0,i;
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
			flag=1;
			break;
	}
	if(flag==0)
		return 0;
	else
		return 1;
}

