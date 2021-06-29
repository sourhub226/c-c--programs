// A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the title and author and the system searches the list and displays whether it is available or not. If it is not, an appropriate message is displayed. If It is then the system displays the book details and requests for the number of copies required. If the requested copies are available the total cost of the requested copies is displayed otherwise the message "Required copies not in stock" is displayed.
#include<iostream>
#include<cstring>
#include <iomanip>
 
using namespace std;

class book
{
	char **author;
	char **title;
	float *price;
	char **publisher;
	int *stock_copy;
	int size;
	 
	public:
		book()
		{
			size=4;
			author=new char*[80];
			title=new char*[80];
			publisher=new char*[80];
			 
			for(int i=0;i<size;i++)
			{
				author[i]=new char[80];
				title[i]=new char[80];
				publisher[i]=new char[80];
			}
			stock_copy=new int[size];
			price=new float[size];
			 
			title[0]="2 states";
			title[1]="machine learning";
			title[2]="cherry tree";
			title[3]="wings of fire";
			 
			author[0]="chetan bhagat";
			author[1]="tom mitchell";
			author[2]="ruskin bond";
			author[3]="abdul kalam";
			 
			stock_copy[0]=200;
			stock_copy[1]=150;
			stock_copy[2]=50;
			stock_copy[3]=80;
			 
			price[0]=350;
			price[1]=170;
			price[2]=140;
			price[3]=310;
		 
		}
		
		void book_detail(int i)
		{
			cout<<" \n********* Book Detail **********\n";
			cout<<"Title\t\t"<<"Author Name\t"<<"Stock copy\n";
			cout<<title[i]<<"\t"<<author[i]<<"\t"<<stock_copy[i]<<"\n";
		}
		
		int search()
		{
			char name[80],t[80];
			cout<<"Enter author name : ";
			gets(name);
			cout<<"Enter title of book : ";
			gets(t);
			 
			int count=-1;
			int a,b;
			for(int i=0;i<size;i++)
			{
				a=strcmp(name,author[i]);
				b=strcmp(t,title[i]);
				if(a==0 && b==0)
					count=i;
			}
			return count;
		}
		 
		void buy(int i)
		{
			if(i<0)
				cout<<"This book is not available \n";
			 
			else
			{
				int copy;
				book_detail(i);
				cout<<"How many copies of this book are required?  "; 
				cin>>copy;
				int remaining_copy;
				if(copy<=stock_copy[i])
				{
					remaining_copy=stock_copy[i]-copy;
					float total_price;
					total_price=price[i]*copy;
					cout<<"Total price = "<<total_price<<"\n";
				}
				else
					cout<<"\nYour required copies are not available \n";
			}
		}
};

int main()
{
	book b1;
	int result;
	result=b1.search();
	b1.buy(result);
	return 0;
}
