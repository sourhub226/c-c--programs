// Write a program with the following:
// (a) A function to read two double type numbers from keyboard.
// (b) A function to calculate the division of these two numbers.
// (c) A try block to throw an exception when a wrong type of data is keyed in.
// (d) A try block to detect and throw an exception if the condition “divide-by-zero” occurs.
// (e) Appropriate catch block to handle the exceptions thrown.

#include <iostream>
using namespace std;

class errorh
{
    double a,b;
    public:
    void read()
    {
        cout<<"Enter two double type numbers: ";
        cin>>a>>b;
    }
    void div()
    {
        try
		{
            if(cin.fail())
                throw "Exception-Wrong type of data entered";
            if( b == 0 )
            	throw 0;
            cout<<"\nQuotient = "<<a/b;
        }
        catch(const int n)
        {
            cout << "\nDivision by " << n << " not allowed\n";
        }
        catch(const char* Str)
        {
            cout<< Str;
        }
    }
};

int main()
{
    errorh k;
    k.read();
    k.div();
    return 0;
}
