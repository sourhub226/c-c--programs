//To draw any 5 animated facial emoji using Mid-point Circle algorithm
#include<graphics.h>

void plot_points(int x,int y,int xC,int yC) {
	putpixel(xC + x,yC + y,YELLOW);
	putpixel(xC + y,yC + x,YELLOW);
	putpixel(xC - x,yC + y,YELLOW);
	putpixel(xC - y,yC + x,YELLOW);
	putpixel(xC - x,yC - y,YELLOW);
	putpixel(xC - y,yC - x,YELLOW);
	putpixel(xC + x,yC - y,YELLOW);
	putpixel(xC + y,yC - x,YELLOW);
}

void midp_circle(int Radius,int xC,int yC) {
	int P;
	int x,y;
	x = 0;
	y = Radius;
	plot_points(x,y,xC,yC);
	P = 1 - Radius;

	while (x<y) {
		x++;
		if (P<0) {
			P += 2 * x + 1;
		} else {
			y--;
			P += 2 * (x - y) + 1;
		}
		plot_points(x,y,xC,yC);
	}
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	sdlbgiauto();
	setcolor(YELLOW);
	while(1) {
		for(int i=0; i<100; i++) {
			cleardevice();
			//emoji 1
			midp_circle(70,80,300);
			midp_circle(15,55,280);
			midp_circle(15,105,280);
			arc(80,310,180+i*0.8,270+i*0.8,30);

			//emoji 2
			midp_circle(70,240,300);
			midp_circle(10+i*0.05,215,280);
			midp_circle(10+i*0.05,265,280);
			midp_circle(5+i*0.2,240,330);

			//emoji 3
			midp_circle(70,400,300);
			ellipse(375,280,0,360,15,18);
			ellipse(425,280,0,360,15,18);
			line(375,330,425,330);
			midp_circle(7,366+i*0.18,275);
			midp_circle(7,416+i*0.18,275);

			//emoji 4
			midp_circle(70,560,300);
			midp_circle(10+i*0.1,535,280);
			midp_circle(20-i*0.1,585,280);
			ellipse(560,310,200,340,40,15);
			ellipse(560,300,200,340,40,50);
			ellipse(560,335-i*0.05,180,360,12+i*0.05,10+i*0.2);

			//emoji 5
			midp_circle(70,720,300);
			midp_circle(20-i*0.05,695,280);
			midp_circle(20-i*0.05,745,280);
			midp_circle(5+i*0.05,695,280);
			midp_circle(5+i*0.05,745,280);
			line(700+i*0.1,330,740-i*0.1,330);

			delay(10);
		}
	}

	closegraph();
	return 0;
}
