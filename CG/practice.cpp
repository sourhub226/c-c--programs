//contains all basic inbuilt fns in graphics.h
//uncomment lines separately to compile and execute it 
#include <graphics.h>
#include <iostream>
using namespace std;

int main() {

	int gd = DETECT, gm;
	initgraph(&gd, &gm,NULL);

	//set bg color
	//setbkcolor(RED);

	//set line color
	//setcolor(GREEN);

	//circle
	//circle(x,y,radius);
	//circle(300,200,50);

	//moving circle
	//	for(int i=0; i<300; i++) {
	//		cleardevice();
	//		circle(100+2*i,100,50);
	//		delay(20);
	//	}

	//arc
	//arc(x,y,startangle,endangle,radius);
	//arc(100,200,30,90,100);

	//polygon
	//int polytriangle[]={100,100,100,50,250,50};
	//drawpoly(num,polypoints); //num is number of sides, polypoints is an array of points;
	//drawpoly(3,polytriangle);//triangle


	//ellipse
	//ellipse(x,y,startangle,endangle,xradius,yradius);
	//ellipse(200,300,0,100,100,50);

	//rectangle
	//rectangle(left,top,right,bottom);
	//rectangle(50,10,200,200);

	//filled shapes
	//fillellipse(x,y,xradius,yradius);
	//fillellipse(200,200,200,100);
	//int polyhexa[]={50,100,100,50,150,50,200,100,150,150,100,150};
	//fillpoly(num,polypoints);
	//fillpoly(6,polyhexa); //hexagon

	//display pixel
	//putpixel(x,y,color);
	//putpixel(100,100,GREEN);

	//flood fill
	//floodfill(x,y,shape border color);
	//setfillstyle(SOLID_FILL, RED); //change floodfill color
	//floodfill(100,100,WHITE);

	//display fns
	//cout<<"Bk color = "<<getbkcolor()<<endl;
	//cout<<"Line color = "<<getcolor()<<endl;
	//cout<<"Max x = "<<getmaxx()<<endl;
	//cout<<"Max y = "<<getmaxy()<<endl;
	//cout<<"Pixel color at (100,100) = "<<getpixel(100,100)<<endl;
	//cout<<"Current x = "<<getx()<<endl;
	//cout<<"Current y = "<<gety()<<endl;

	getch();
	closegraph();
	return 0;
}


