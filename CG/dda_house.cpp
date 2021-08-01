//To draw a house using DDA line drawing algorithm
#include<graphics.h>

void dda_line(float x1,float y1,float x2,float y2) {
	float x,y,dx,dy,step,i=0;

	dx=x2-x1;
	dy=y2-y1;

	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	dx=dx/step;
	dy=dy/step;

	x=x1;
	y=y1;

	while(i<=step) {
		putpixel(x,y,WHITE);
		x=x+dx;
		y=y+dy;
		i++;
	}
}

int main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	sdlbgiauto();

	//house
	//roof
	dda_line(400,50,140,220);
	dda_line(400,50,660,220);
	dda_line(400,80,155,240);
	dda_line(400,80,645,240);
	dda_line(140,220,155,240);
	dda_line(660,220,645,240);
	//chimney
	dda_line(490,60,490,108);
	dda_line(550,60,550,148);
	dda_line(490,60,550,60);
	dda_line(490,45,490,60);
	dda_line(550,45,550,60);
	dda_line(490,45,550,45);
	//front entrance
	dda_line(200,210,200,550);
	dda_line(600,210,600,550);
	dda_line(200,550,600,550);
	//entrance door
	dda_line(220,540,380,540);
	dda_line(220,540,220,550);
	dda_line(380,540,380,550);
	dda_line(240,350,240,540);
	dda_line(360,350,360,540);
	dda_line(240,350,360,350);
	//door handle
	dda_line(350,450,350,470);
	dda_line(345,450,345,470);
	dda_line(345,450,350,450);
	dda_line(345,470,350,470);
	//top window
	dda_line(330,170,470,170);
	dda_line(330,270,470,270);
	dda_line(330,170,330,270);
	dda_line(470,170,470,270);
	dda_line(330,220,470,220);
	dda_line(400,170,400,270);
	//bottom window
	dda_line(430,350,530,350);
	dda_line(430,450,530,450);
	dda_line(430,350,430,450);
	dda_line(530,350,530,450);
	dda_line(480,350,480,450);
	dda_line(430,400,530,400);

	getch();
	closegraph();
}
