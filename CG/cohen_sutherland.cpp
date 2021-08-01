//To implement Cohen-Sutherland Line Clipping Algorithm.
#include<graphics.h>
#include<iostream>
#include<tuple>
using namespace std;

int xwmin,ywmin,xwmax,ywmax;

void draw_fig(float x1,float y1,float x2,float y2,char * message) {
	cleardevice();
	setcolor(WHITE);
	outtextxy(340,10,message);

	//line
	setlinestyle(0,0,1);
	line(x1,y1,x2,y2);

	//window
	setlinestyle(1,0,1);
	setcolor(RED);
	line(xwmin,ywmin,xwmin,ywmax);
	line(xwmax,ywmin,xwmax,ywmax);
	line(xwmin,ywmin,xwmax,ywmin);
	line(xwmin,ywmax,xwmax,ywmax);
}

int get_bit(float n1,float n2) {
	return ((n1-n2>=0)? 0:1);
}

tuple<int, int, int, int> get_region_code(float x,float y) {
	return make_tuple(get_bit(ywmax,y),get_bit(y,ywmin),get_bit(xwmax,x),get_bit(x,xwmin));
}

void print_region_code(tuple<int, int, int, int> t) {
	cout<<get<0>(t)<<get<1>(t)<<get<2>(t)<<get<3>(t);
	string decision=t!=make_tuple(0,0,0,0)? "outside":"inside";
	cout<<endl<<"=> The point lies "<<decision<<" the window";
}

tuple<float,float> clip(float x1, float y1, tuple<int, int, int, int> r, float m) {
	float x,y;
	if (get<0>(r)==1) {
		cout<<endl<<"Clip against top boundary";
		y=ywmax;
		x=x1+(1/m)*(y-y1);
	} else if (get<1>(r)==1) {
		cout<<endl<<"Clip against bottom boundary";
		y=ywmin;
		x=x1+(1/m)*(y-y1);
	} else if (get<2>(r)==1) {
		cout<<endl<<"Clip against right boundary";
		x=xwmax;
		y=y1+m*(x-x1);
	} else if (get<3>(r)==1) {
		cout<<endl<<"Clip against left boundary";
		x=xwmin;
		y=y1+m*(x-x1);
	}
	return make_tuple(x,y);
}

tuple<int, int, int, int> perform_and(tuple<int, int, int, int> t1,tuple<int, int, int, int> t2) {
	return make_tuple(get<0>(t1) & get<0>(t2),get<1>(t1) & get<1>(t2),get<2>(t1) & get<2>(t2),get<3>(t1) & get<3>(t2));
}

void cohen_sutherland(float x1,float y1,float x2,float y2) {
	tuple <int, int, int,int> ARcode,BRcode,ZERORcode,and_result;
	ZERORcode=make_tuple(0,0,0,0);
	tuple <float,float> temp;

	float m=(y2-y1)/(x2-x1);
	cout<<endl<<"Slope = "<<m;

	while(true) {
		ARcode=get_region_code(x1,y1);
		cout<<endl<<endl<<"Region code of A = ";
		print_region_code(ARcode);
		BRcode=get_region_code(x2,y2);
		cout<<endl<<"Region code of B = ";
		print_region_code(BRcode);

		//cases
		if(ARcode==ZERORcode && BRcode==ZERORcode) {
			cout<<endl<<endl<<"No more clipping is required."<<endl;
			cout << "Line is visible and accepted between (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 <<")"<< endl;
			draw_fig(x1,y1,x2,y2,"- After clipping -");
			break;
		} else if(ARcode==ZERORcode && BRcode!=ZERORcode) {
			cout<<endl<<endl<<"Consider point B("<<x2<< "," << y2 << ")";
			temp=clip(x1,y1,BRcode,m);
			x2=get<0>(temp);
			y2=get<1>(temp);
			cout<<endl<<"New B point = "<<"("<<x2<< "," << y2 << ")";

		} else if(ARcode!=ZERORcode && BRcode==ZERORcode) {
			cout<<endl<<endl<<"Consider point A("<<x1<< "," << y1 << ")";
			temp=clip(x2,y2,ARcode,m);
			x1=get<0>(temp);
			y1=get<1>(temp);
			cout<<endl<<"New A point = "<<"("<<x1<< "," << y1 << ")";
		} else {
			cout<<endl<<endl<<"Both region codes are non-zero => perform AND operation";
			and_result=perform_and(ARcode,BRcode);
			if (and_result!=ZERORcode) {
				cout<<endl<<"AND result is not zero";
				cout<<endl<<"Line is invisible and rejected";
				break;
			} else {
				cout<<endl<<"AND result is zero";
				cout<<endl<<"=> Line may be partially visible";

				cout<<endl<<endl<<"Consider point A("<<x1<< "," << y1 << ")";
				temp=clip(x2,y2,ARcode,m);
				x1=get<0>(temp);
				y1=get<1>(temp);
				cout<<endl<<"New A point = "<<"("<<x1<< "," << y1 << ")";

				cout<<endl<<endl<<"Consider point B("<<x2<< "," << y2<< ")";
				temp=clip(x1,y1,BRcode,m);
				x2=get<0>(temp);
				y2=get<1>(temp);
				cout<<endl<<"New B point = "<<"("<<x2<< "," << y2 << ")";
			}
		}
	}
}

int main() {
	float x1,y1,x2,y2;
	cout<<"Enter (xwmin,ywmin):"<<endl;
	cout<<"\txwmin = ";
	cin>>xwmin;
	cout<<"\tywmin = ";
	cin>>ywmin;
	cout<<endl<<"Enter (xwmax,ywmax):"<<endl;
	cout<<"\txwmax = ";
	cin>>xwmax;
	cout<<"\tywmax = ";
	cin>>ywmax;

	cout<<endl<<"Enter point A(x1,y1):"<<endl;
	cout<<"\tx1 = ";
	cin>>x1;
	cout<<"\ty1 = ";
	cin>>y1;
	cout<<endl<<"Enter point B(x2,y2):"<<endl;
	cout<<"\tx2 = ";
	cin>>x2;
	cout<<"\ty2 = ";
	cin>>y2;


	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	sdlbgiauto();

	cout<<endl<<"Press a key to clip the line"<<endl;
	draw_fig(x1,y1,x2,y2,"- Before clipping -");

	getch();

	cohen_sutherland(x1,y1,x2,y2);

	getch();
	closegraph();
}
