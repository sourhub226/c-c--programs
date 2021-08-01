#include<graphics.h>
#include<iostream>
using namespace std;

void ellipsePlotPoints (int xCenter, int yCenter, int x, int y) {
	cout<<endl;
	cout<<"("<<xCenter+x<<","<<yCenter+y<<") , ";
	cout<<"("<<xCenter-x<<","<<yCenter+y<<") , ";
	cout<<"("<<xCenter-x<<","<<yCenter-y<<") , ";
	cout<<"("<<xCenter+x<<","<<yCenter-y<<") , ";
	putpixel (xCenter + x, yCenter + y,7);
	putpixel (xCenter - x, yCenter + y,7);
	putpixel (xCenter + x, yCenter - y,7);
	putpixel (xCenter - x, yCenter - y,7);
}


void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry) {
	int Rx2 = Rx * Rx;
	int Ry2 = Ry * Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2 * y;
	int i=0;


	/* Region 1 */
	cout<<"\nREGION 1"<<endl;
	ellipsePlotPoints (xCenter, yCenter, x, y);


	p = round (Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
	cout<<endl<<"\nP10 = "<<p;


	while (px < py) {
		x++;
		px += twoRy2;
		if (p < 0) {
			p += Ry2 + px;
			cout<<endl<<"P1"<<i<<"<0";
		}

		else {
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
			cout<<endl<<"P1"<<i<<">=0";
		}
		i++;
		ellipsePlotPoints (xCenter, yCenter, x, y);
		cout<<endl<<px<<"<"<<py;
		string decision=px < py? "True":"False";
		cout<<"\t"<<decision;
		if(decision!="False") cout<<endl<<"\nP1"<<i<<" = "<<p;

	}


	i=0;
	/* Region 2 */
	cout<<endl<<endl<<"REGION 2"<<endl;
	p = round (Ry2 * (x+0.5) * (x+0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
	cout<<endl<<"P20 = "<<p;
	while (y > 0) {
		y--;
		py -= twoRx2;
		if (p > 0) {
			p += Rx2 - py;
			cout<<endl<<"P2"<<i<<">0";
		}

		else {
			x++;
			px += twoRy2;
			p += Rx2 - py + px;
			cout<<endl<<"P2"<<i<<"<=0";
		}
		i++;
		ellipsePlotPoints (xCenter, yCenter, x, y);
		cout<<endl<<y<<">"<<"0";
		string decision=y>0? "True":"False";
		cout<<"\t"<<decision;
		if(decision!="False") cout<<endl<<"\nP2"<<i<<" = "<<p;
	}
}


int main() {
	int gdriver=DETECT, gmode;

	int Xc,Yc,Rx,Ry;
	cout << "Enter (Xc,Yc):"<<endl;
	cout<<"Xc: ";
	cin>>Xc;
	cout<<"Yc: ";
	cin>>Yc;
	cout<<"Enter Rx: ";
	cin>>Rx;
	cout<<"Enter Ry: ";
	cin>>Ry;

	initgraph(&gdriver, &gmode, NULL);
	ellipseMidpoint(Xc,Yc,Rx,Ry);
	getch();
	closegraph();
	return 0;
}
