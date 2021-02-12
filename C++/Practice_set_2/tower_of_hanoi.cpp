// Solve the tower of hanoi recursively with appropriate assumptions.
#include<iostream>
using namespace std;
 
void tower(int n,char from,char to, char aux)
{
    if (n==1)
    {
        cout<<"Move disk 1 from "<<from<<" to "<< to<<endl;
        return;
    }
    tower(n-1,from,aux,to);
    cout<<"Move disk "<<n<<" from "<<from<<" to "<< to<<endl;
    tower(n-1,aux,to,from);
}

int main()
{
    int n,a;
    cout<<"Enter the number of disks : ";
    cin>>n;
    cout<<endl<<"The sequence of steps involved are :"<<endl;
    tower(n,'A','C','B');
}

