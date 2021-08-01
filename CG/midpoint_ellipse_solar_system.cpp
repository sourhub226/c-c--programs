//To draw an animated solar system using Mid-point Ellipse algorithm
#include<graphics.h>
#include<iostream>
using namespace std;

int screenCenterX=400,screenCenterY=300;

void plotPoints (int xCenter, int yCenter, int x, int y) {
	putpixel (xCenter + x, yCenter + y,WHITE);
	putpixel (xCenter - x, yCenter + y,WHITE);
	putpixel (xCenter + x, yCenter - y,WHITE);
	putpixel (xCenter - x, yCenter - y,WHITE);
}

void midpoint_ellipse (int xCenter, int yCenter, int Rx, int Ry) {
	long long Rx2 = Rx * Rx;
	long long Ry2 = Ry * Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2 * y;

	/* Region 1 */
	plotPoints (xCenter, yCenter, x, y);
	p = round (Ry2 - (Rx2 * Ry) + (0.25 * Rx2));

	while (px < py) {
		x++;
		px += twoRy2;
		if (p < 0) {
			p += Ry2 + px;
		} else {
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		plotPoints (xCenter, yCenter, x, y);
	}

	/* Region 2 */
	p = round (Ry2 * (x+0.5) * (x+0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);

	while (y > 0) {
		y--;
		py -= twoRx2;
		if (p > 0) {
			p += Rx2 - py;
		} else {
			x++;
			px += twoRy2;
			p += Rx2 - py + px;
		}
		plotPoints (xCenter, yCenter, x, y);
	}
}

void move_planet(char *planet,int move_rx,int move_ry,int speed,int erx,int ery) {
	int x,y;
	x = screenCenterX + (move_rx * cos(speed*.005));
	y= screenCenterY + (move_ry * sin(speed*.005));
	midpoint_ellipse(x,y,erx,ery);
	outtextxy(x+5,y-ery,planet);
}

int main() {
	int gd = DETECT, gm,i=0;
	initgraph(&gd, &gm, "");
	sdlbgiauto();
	while(i+=1) {
		cleardevice();

		//sun
		midpoint_ellipse(screenCenterX,screenCenterY,50,50);
		outtextxy(screenCenterX-10,screenCenterY,"Sun");

		//mercury
		midpoint_ellipse(screenCenterX,screenCenterY,100,60);
		move_planet("Mercury",100,60,i*3.2,8,8);

		//venus
		midpoint_ellipse(screenCenterX,screenCenterY,130,70);
		move_planet("Venus",130,70,i*2.3,9,9);

		//earth
		midpoint_ellipse(screenCenterX,screenCenterY,170,85);
		move_planet("Earth",170,85,i*2,10,10);

		//mars
		midpoint_ellipse(screenCenterX,screenCenterY,200,100);
		move_planet("Mars",200,100,i*1.6,6,6);

		//jupiter
		midpoint_ellipse(screenCenterX,screenCenterY,240,120);
		move_planet("Jupiter",240,120,i*0.8,20,20);

		//saturn
		midpoint_ellipse(screenCenterX,screenCenterY,290,150);
		move_planet("Saturn",290,150,i*0.6,17,17);
		move_planet("",290,150,i*0.6,30,10);

		//uranus
		midpoint_ellipse(screenCenterX,screenCenterY,340,180);
		move_planet("Uranus",340,180,i*0.45,13,13);

		//neptune
		midpoint_ellipse(screenCenterX,screenCenterY,390,210);
		move_planet("Neptune",390,210,i*0.36,12,12);
		
		delay(10);
	}
	getch();
	closegraph();
}
