// Write an interactive, menu-driven program that will access the file created in previous exercise 
// and implement the tasks:
// (a) Determine the telephone number of the specified person.
// (b) Determine the name if a telephone number is known.
// (c) Update, the telephone number, whenever there is a change.

#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std; 
int main()
{
    char name[100],n[100],m[100],number[100];
    int test;
    ifstream  fin("telephone.txt");

    cout<<"Press 1 to find mobile number of specified person\n";
    cout<<"Press 2 to find name of specified number\n";
    cout<<"Press 3 to update number\n";
    cout<<"Enter your choice: "; 
    cin>>test;
 	
	switch(test)
	{
 		case 1:
		 	cout<<"Enter the desired name : ";
        	cin>>n;
        	cout<<"\n";
        	again1:
	            fin>>name;
	            if(!strcmp(name,n))
	            {
	                fin.getline(number,100);
	                cout<<name<<number<<"\n";
	            }
	            else
	            {
	            	if(fin.eof()!=0)
	                	cout<<"Sorry your input name is not found in list \n";
	                else
	                    goto again1;
	            }
			break;
		case 2:
			cout<<"Enter the desired number : ";
            cin>>n;
            cout<<"\n";
            again2:
                fin>>name;
                fin>>number;
 
                if(!strcmp(number,n))
    				cout<<number<<setw(7)<<name<<"\n";
				else
                {
                    if(fin.eof()!=0)
                        cout<<"Sorry your input number is not found in list \n";
                    else
                        goto again2;
                }
			break;
		case 3:
			ofstream fout("modified telephone.txt");
            cout<<"Enter the name whose number have to change : ";
            cin>>n;
            again3:
                fin>>name>>number;
                         
                if(!strcmp(n,name))
                {
                    cout<<"Enter changed mobile number of "<<name<<":   ";
                    cin>>m;
                    fout.setf(ios::left,ios::adjustfield);
                    fout.width(20);
                    fout<<name;
                    fout.setf(ios::right,ios::adjustfield);
                    fout.width(15);
                    fout<<m<<"\n";
                    while(fin)
                    {
                        fin>>name>>number;
                        fout.setf(ios::left,ios::adjustfield);
                        fout.width(20);
                        fout<<name;
                        fout.setf(ios::right,ios::adjustfield);
                        fout.width(15);
                        fout<<number<<"\n";
                    }
                }
        		else
          		{
                   if(fin.eof()!=0)
                   cout<<"Sorry your input name is not available \n";
                   else
                   {
                        fout.setf(ios::left,ios::adjustfield);
                        fout.width(20);
                        fout<<name;
                        fout.setf(ios::right,ios::adjustfield);
                        fout.width(15);
                        fout<<number<<"\n";
                        goto again3;
                    }
         		}	
	}
    return 0;
}
