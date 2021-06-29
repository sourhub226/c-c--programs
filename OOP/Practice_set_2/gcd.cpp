// Write a recursive definition of the function "greatest_common_divisor(...)", which takes two positive integer arguments and returns their greatest common divisor.
#include <iostream> 
using namespace std; 

int gcd(int a, int b) 
{ 
	if (b==0) 
        return a; 
    return gcd(b,a%b);  
} 

int main() 
{ 
    int a,b;
    cout<<"Enter 2 nos: ";
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a,b); 
} 
