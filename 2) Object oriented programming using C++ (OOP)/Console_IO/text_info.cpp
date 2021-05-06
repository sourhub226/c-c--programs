// Write a program which reads a text from the keyboard and displays the following
// information on the screen in two columns:
// (a) Number of lines
// (b) Number of words
// (c) Number of characters

#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int main()
{
	char line[1000];
	char ch;
	int c;
	int word,lines,chr;
	word=0;
	lines=0;
	chr=0;
	int end=0;
	cout<<"Enter text : \n";
	while(end==0)
	{
		c=0;
		int i=0;
		while((ch=getchar())!='\n')
		{
			line[i]=ch;
			i++;
		}
		line[i]='\0';

		if(line[0]=='\0')
			break;
		else
		{
			word++;
			for(int i=0;line[i]!='\0';i++)
				if(line[i]==' ' || line[i]=='\t' || line[i]=='\n')
					word++;
		}
		lines++;
		chr+=strlen(line);
	}

	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(25)<<"Number of lines"<<setw(25)<<"Number of words "<<setw(25)<<"Number of characters "<<endl;
	cout.setf(ios::right,ios::adjustfield);
	cout<<setw(14)<<lines<<setw(25)<<word<<setw(30)<<chr<<endl;
}
