# include <iostream>
# include <iomanip>
# include <graphics.h>
using namespace std;

void Draw(int x,int y,int xC,int yC) {
	cout<<endl;
	cout<<"("<<xC+x<<","<<yC+y<<") , ";
	cout<<"("<<xC+y<<","<<yC+x<<") , ";
	cout<<"("<<xC-x<<","<<yC+y<<") , ";
	cout<<"("<<xC-y<<","<<yC+x<<") , ";
	cout<<"("<<xC-x<<","<<yC-y<<") , ";
	cout<<"("<<xC-y<<","<<yC-x<<") , ";
	cout<<"("<<xC+x<<","<<yC-y<<") , ";
	cout<<"("<<xC+y<<","<<yC-x<<") , ";

	putpixel(xC + x,yC + y,12);
	putpixel(xC + y,yC + x,12);
	putpixel(xC - x,yC + y,12);
	putpixel(xC - y,yC + x,12);
	putpixel(xC - x,yC - y,12);
	putpixel(xC - y,yC - x,12);
	putpixel(xC + x,yC - y,12);
	putpixel(xC + y,yC - x,12);
}

void Circle(int Radius,int xC,int yC) {
	int P;
	int x,y;
	int i=0;
	x = 0;
	y = Radius;
	Draw(x,y,xC,yC);
	P = 1 - Radius;
	cout<<endl<<endl<<"P0 = "<<P;

	while (x<y) {
		x++;
		if (P<0) {

			P += 2 * x + 1;
			cout<<endl<<"P"<<i<<"<0";
		} else {
			y--;
			P += 2 * (x - y) + 1;
			cout<<endl<<"P"<<i<<">=0";

		}
		Draw(x,y,xC,yC);
		i++;
		cout<<endl<<x<<"<"<<y;
		string decision=x < y? "True":"False";
		cout<<"\t"<<decision;
		if(decision!="False") cout<<endl<<endl<<"P"<<i<<" = "<<P;
	}
}

int main() {
	int Radius, xC, yC;
	cout << "Enter (Xc,Yc):"<<endl;
	cout<<"Xc: ";
	cin>>xC;
	cout<<"Yc: ";
	cin>>yC;
	cout<<"Enter Radius: ";
	cin>>Radius;

	int gDriver=DETECT, gMode;
	initgraph(&gDriver,&gMode,NULL);

	cleardevice();
	Circle(Radius,xC,yC);
	getch();
	return 0;
}

