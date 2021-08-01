//To test graphics.h installation using this program.
#include <graphics.h>

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm,NULL);
	sdlbgiauto();

	//line(x1,y1,x2,y2);
	line(100,100,300,500);

	//circle(x,y,radius);
	circle(200,150,70);

	//animated circle (circle moves from x=200 to x=500)
	for(int i=0; i<300; i++) {
		cleardevice();
		circle(200+i,150,70);
		delay(20);
	}

	getch();
	closegraph();
	return 0;
}


