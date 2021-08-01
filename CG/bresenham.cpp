//generalised bresenham line drawing algo (works for all cases of slope)

#include <graphics.h>
#include<iostream>
using namespace std;

int main() {
	int gd = DETECT, gm;
	int dx,dy,s1,s2,pk,x,y,x1,y1,x2,y2,i=0;

	cout<<"Enter (x1,y1):\n";
	cout<<"x1: ";
	cin>>x1;
	cout<<"y1: ";
	cin>>y1;
	cout<<"Enter (x2,y2):\n";
	cout<<"x2: ";
	cin>>x2;
	cout<<"y2: ";
	cin>>y2;

	initgraph(&gd, &gm, "");
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	s1=x2>x1? 1:-1;
	s2=y2>y1? 1:-1;

	cout<<"\nSlope = "<<round((float(s2*dy)/(s1*dx))*100.0)/100.0<<endl;
	x=x1;
	y=y1;
	cout<<"\n(x0,y0) = ";
	cout<<"("<<x<<","<<y<<")"<<endl;
	putpixel(x,y,WHITE);

	if(dx>dy) {
		pk=2*dy-dx;
		while(!(x==x2 && y==y2)) {
			cout<<"\nP"<<i<<" = "<<pk<<endl;
			if(pk>=0) {
				x=x+s1;
				y=y+s2;
				pk=pk+2*dy-2*dx;
				cout<<"P"<<i<<">=0"<<endl;
			} else {
				x=x+s1;
				pk=pk+2*dy;
				cout<<"P"<<i<<"<0"<<endl;
			}
			i++;
			putpixel(x,y,WHITE);
			cout<<"(x"<<i<<",y"<<i<<") = ";
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
	}

	else if(dy>dx) {
		pk=2*dx-dy;
		while(!(x==x2 && y==y2)) {
			cout<<"\nP"<<i<<" = "<<pk<<endl;
			if(pk>=0) {
				x=x+s1;
				y=y+s2;
				pk=pk+2*dx-2*dy;
				cout<<"P"<<i<<">=0"<<endl;
			} else {
				y=y+s2;
				pk=pk+2*dx;
				cout<<"P"<<i<<"<0"<<endl;
			}
			i++;
			putpixel(x,y,WHITE);
			cout<<"(x"<<i<<",y"<<i<<") = ";
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
	}
	getch();
	closegraph();

	return 0;
}
