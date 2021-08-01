//To draw your name in animated Devanagari and English
#include <graphics.h>

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm,NULL);
	sdlbgiauto();

	//English
	for(int i = 0; i<=100; i++) {
		cleardevice();
		//s
		arc(50,200,i*0.3,i*2.7,40);
		arc(50,280,-1.6*i,i*0.9,40);
		//o
		circle(170,245,i*0.65);
		//u
		line(260,165,260,165+i*1.10);
		line(350,165,350,165+i*1.10);
		arc(305,270,i*1.8,i*3.6,45);
		//r
		line(370,160,370,160+i*1.60);
		ellipse(370,210,-90,90,i*0.7,50);
		line(370,260,370+i*0.6,260+i*0.6);
		//a
		ellipse(520,255,0,i*1.80,53,93);
		line(467,255,467,255+i*0.55);
		line(572,255,572,255+i*0.55);
		line(467,250,467+i*1.05,250);
		//b
		line(600,159,600,159+i*1.51);
		ellipse(600,197,-90,90,i*0.7,38);
		ellipse(600,273,-90,90,70,i*0.38);
		//h
		line(700,155,700,155+i*1.55);
		line(790,310-i*1.55,790,310);
		line(745-i*0.45,230,745+i*0.45,230);
		delay(20);
	}
	outtextxy(370, 530, "English");

	getch();

	//devnagri
	for(int i = 0; i<=100; i++) {
		cleardevice();
		//top line
		line(170,170,170+i*4.4,170);
		//sou
		ellipse(170,220,-0.9*i,90,i*0.80,50);
		line(170,270,230,270+i*0.8);
		line(300-i*1.3,271,300,271);
		line(300,170,300,170+i*1.8);
		line(320,350-i*1.8,320,350);
		line(230+i*0.9,100+i*0.7,230,100);
		line(320,85+i*0.85,320-i*0.6,85);
		//ra
		ellipse(355,220,-90,90,80,i*0.50);
		line(355,350-i*0.8,415,350);
		//bh
		arc(500,210,0,i*2.70,40);
		arc(520,300,i*0.90,i*3.60,20);
		line(540,201,540,300);
		line(540-i*0.5,250,540,250);
		line(520,280,520+i*0.7,280);
		line(590,170,590,170+i*1.8);
		delay(20);
	}
	outtextxy(360, 530, "Devanagari");

	getch();
	closegraph();
	return 0;
}
