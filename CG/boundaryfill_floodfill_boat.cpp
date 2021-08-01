//To draw and colour animated boat using Boundaryfill and Floodfill Algorithm.
#include<graphics.h>

void flood_fill(int x,int y,int fillColor, int defaultColor) {
	if(getpixel(x,y)==defaultColor) {
		putpixel(x,y,fillColor);
		flood_fill(x+1,y,fillColor,defaultColor);
		flood_fill(x-1,y,fillColor,defaultColor);
		flood_fill(x,y+1,fillColor,defaultColor);
		flood_fill(x,y-1,fillColor,defaultColor);
	}
}

void boundary_fill4(int x, int y, int fill_color,int boundary_color) {
	if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
		putpixel(x, y, fill_color);
		boundary_fill4(x + 1, y, fill_color, boundary_color);
		boundary_fill4(x, y + 1, fill_color, boundary_color);
		boundary_fill4(x - 1, y, fill_color, boundary_color);
		boundary_fill4(x, y - 1, fill_color, boundary_color);
	}
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	sdlbgiauto();
	int i,angle=0;
	float x,y;
	float multiplier=5;

	for(i = 0; i < getmaxx(); i++) {
		cleardevice();
		setcolor(BLUE);
		angle=0;

		//wave
		for(x = 0; x < getmaxx(); x++) {
			y = 10*sin(angle*3.141/180)+400;
			putpixel(x, y, BLUE);
			angle++;

		}
		line(0,getmaxy(),getmaxx(),getmaxy());
		line(0,400,0,getmaxy());
		line(getmaxx(),400,getmaxx(),getmaxy());

		flood_fill(getmaxx()-10,getmaxy()-10,BLUE,BLACK); //flood fill water wave

		//boat
		setcolor(WHITE);
		line(getmaxx(),0,getmaxx(),getmaxy());

		int boat_body[]= {0+i*multiplier,360,300+i*multiplier,360,180+i*multiplier,415,30+i*multiplier,415};
		drawpoly(4,boat_body);
		fillellipse(25+i*multiplier,373,7,7);
		fillellipse(45+i*multiplier,373,7,7);
		fillellipse(65+i*multiplier,373,7,7);
		line(20+i*multiplier,360,50+i*multiplier,330);
		line(50+i*multiplier,330,190+i*multiplier,330);
		ellipse(175+i*multiplier,380,23,80,85,50);
		line(75+i*multiplier,330,60+i*multiplier,300);
		line(115+i*multiplier,330,70+i*multiplier,300);
		line(60+i*multiplier,300,70+i*multiplier,300);
		ellipse(150+i*multiplier,380,30,150,100,40);
		setlinestyle(0, 0, 3);
		line(150+i*multiplier,340,150+i*multiplier,360);
		setlinestyle(0, 0, 1);

		boundary_fill4(2+i*multiplier,361,RED,WHITE); //boundary fill boat body
		boundary_fill4(152+i*multiplier,350,BLACK,WHITE);
		boundary_fill4(148+i*multiplier,350,BLACK,WHITE);
		boundary_fill4(40+i*multiplier,350,WHITE,WHITE);
		boundary_fill4(62+i*multiplier,301,RED,WHITE);

		delay(multiplier*5);
	}

	getch();
	closegraph();
}
