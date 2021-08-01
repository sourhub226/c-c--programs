//dda line drawing algorithm
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	float x,y,x1,y1,x2,y2,dx,dy,step;

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

	dx=x2-x1;
	dy=y2-y1;
	cout<<endl<<"Slope = "<<dy/dx<<endl<<endl<<"Points: "<<endl;

	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	dx=dx/step;
	dy=dy/step;

	x=x1;
	y=y1;

	int i=0,gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	while(i<=step) {
		x=round(x*100.0)/100.0; //explicit rounding of obtained value to 2 digits for displaying
		y=round(y*100.0)/100.0;
		cout<<"(x"<<i<<","<<"y"<<i<<") \t=\t "<<"("<<x<<","<<y<<") \t\t=\t "<<"("<<round(x)<<","<<round(y)<<")"<<endl;
//		cout<<"(x"<<i<<","<<"y"<<i<<") \t=\t "<<fixed << setprecision(2)<<"("<<x<<","<<y<<") \t\t=\t "<< setprecision(0)<<"("<<round(x)<<","<<round(y)<<")"<<endl;
		putpixel(x,y,RED);
		x=x+dx;
		y=y+dy;
		i++;
	}

	getch();
	closegraph();
}
