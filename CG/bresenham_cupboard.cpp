//To draw a cupboard using Bresenham line drawing algorithm
#include <graphics.h>

void plot_points(int lcase,int d1,int d2,int x,int y,int x2,int y2,int xincr,int yincr) {
	int pk=2*d1-d2;
	while(!(x==x2 && y==y2)) {
		if(pk>=0) {
			x=x+xincr;
			y=y+yincr;
			pk=pk+2*d1-2*d2;
		} else {
			if (!lcase)x=x+xincr;
			else y=y+yincr;
			pk=pk+2*d1;
		}
		putpixel(x,y,WHITE);
	}
}

void bresenham_line(int x1,int y1,int x2,int y2) {
	//generalised algo (works for all cases of slope)
	int dx,dy,s1,s2,x,y;
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	s1=x2>x1? 1:-1;
	s2=y2>y1? 1:-1;

	x=x1;
	y=y1;
	putpixel(x,y,WHITE);

	if(dx>dy)
		plot_points(0,dy,dx,x,y,x2,y2,s1,s2);	//case 1
	else if(dy>dx)
		plot_points(1,dx,dy,x,y,x2,y2,s1,s2);	//case 2
}

int main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	sdlbgiauto();

	//cupboard
	//body
	bresenham_line(250,50,550,50);
	bresenham_line(250,550,550,550);
	bresenham_line(250,50,250,550);
	bresenham_line(550,50,550,550);
	//base
	bresenham_line(260,550,260,570);
	bresenham_line(300,550,300,570);
	bresenham_line(260,570,300,570);
	bresenham_line(540,550,540,570);
	bresenham_line(500,550,500,570);
	bresenham_line(500,570,540,570);
	//bottom drawer 1
	bresenham_line(270,470,530,470);
	bresenham_line(270,530,530,530);
	bresenham_line(270,470,270,530);
	bresenham_line(530,470,530,530);
	//bottom drawer 1 handle
	bresenham_line(370,480,430,480);
	bresenham_line(370,490,430,490);
	bresenham_line(370,480,370,490);
	bresenham_line(430,480,430,490);
	//bottom drawer 2
	bresenham_line(270,400,530,400);
	bresenham_line(270,460,530,460);
	bresenham_line(270,400,270,460);
	bresenham_line(530,400,530,460);
	//bottom drawer 2 handle
	bresenham_line(370,410,430,410);
	bresenham_line(370,420,430,420);
	bresenham_line(370,410,370,420);
	bresenham_line(430,410,430,420);
	//left door
	bresenham_line(270,70,270,380);
	bresenham_line(395,70,395,380);
	bresenham_line(270,70,395,70);
	bresenham_line(270,380,395,380);
	//left door handle
	bresenham_line(385,200,385,250);
	bresenham_line(375,200,375,250);
	bresenham_line(375,200,385,200);
	bresenham_line(375,250,385,250);
	//right door
	bresenham_line(405,70,405,380);
	bresenham_line(530,70,530,380);
	bresenham_line(405,70,530,70);
	bresenham_line(405,380,530,380);
	//right door handle
	bresenham_line(425,200,425,250);
	bresenham_line(415,200,415,250);
	bresenham_line(415,200,425,200);
	bresenham_line(415,250,425,250);

	getch();
	closegraph();
	return 0;
}
