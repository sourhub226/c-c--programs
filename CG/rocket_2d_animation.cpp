//To perform a 2D animations using prefined fns in graphics.h
#include <graphics.h>

void draw_rocket() {
	setcolor(WHITE);
	setfillstyle(1,WHITE);

	//body
	ellipse(400,260,-40,220,40,100);
	ellipse(400,180,220,320,40,20);
	line(370,325,430,325);
	ellipse(410,325,180,210,40,60);
	ellipse(390,325,330,360,40,60);
	line(375,355,425,355);
	floodfill(400,280,WHITE);
	setfillstyle(1,RED);
	floodfill(400,170,WHITE);
	floodfill(400,345,WHITE);

	//left wing
	int left_wing[]= {360,280,330,300,330,360,345,320,365,310};
	fillpoly(5,left_wing);

	//right wing
	int right_wing[]= {440,280,470,300,470,360,455,320,435,310};
	fillpoly(5,right_wing);

	//window
	setcolor(BLACK);
	circle(400,240,25);
	circle(400,240,14);
	setfillstyle(1,COLOR(69,144,201));
	floodfill(400,235,BLACK);
	setfillstyle(1,COLOR(62,60,137));
	floodfill(400,220,BLACK);
}

void draw_earth(int i,int l1[],int l2[]) {
	setcolor(BLACK);
	setfillstyle(1,COLOR(26,126,178));
	ellipse(400,655+i,10,170,420,300);
	floodfill(400,360+i,BLACK);
	setfillstyle(1,COLOR(173,240,63));
	fillpoly(12,l1);
	fillpoly(7,l2);
}

void draw_fire(int i) {
	setcolor(WHITE);
	setfillstyle(1,COLOR(253,152,34));
	ellipse(400,356,180,360,20+i/50,45+i/2);
	floodfill(400,360,WHITE);
	setfillstyle(1,COLOR(255,235,63));
	ellipse(400,356,180,360,15-i/20,30-i/50);
	floodfill(400,358,WHITE);
}

void draw_stars() {
	int k=100;
	while(k--) {
		int p=rand()%400;
		int q=rand()%600;
		if(k%10==0) line(300+p/2,400+q/6,300+p/2,550+q/6);
		putpixel(p,q,WHITE);
		putpixel(400+p,q,WHITE);
	}
}

void draw_moon(int i) {
	setfillstyle(1,WHITE);
	fillellipse(150,-100+i,70,70);
	setfillstyle(1,COLOR(233,237,240));
	fillellipse(130,-110+i,20,20);
	fillellipse(170,-70+i,13,13);
	fillellipse(140,-70+i,7,7);
	fillellipse(180,-130+i,10,10);
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm,NULL);
	sdlbgiauto();

	int land1_points[]= {120,460,100,490,120,530,150,560,220,510,260,510,280,550,340,530,360,460,320,430,300,410,200,410};
	int land2_points[]= {610,500,520,450,470,460,420,500,440,580,510,650,620,570};

	//scene 1
	setbkcolor(COLOR(168,223,255));
	draw_rocket();
	draw_earth(0,land1_points,land2_points);
	getch();

	for(int i=0; i<=100; i++) {
		int land1_points[]= {120,460+i*3,100,490+i*3,120,530+i*3,150,560+i*3,220,510+i*3,260,510+i*3,280,550+i*3,340,530+i*3,360,460+i*3,320,430+i*3,300,410+i*3,200,410+i*3};
		int land2_points[]= {610,500+i*3,520,450+i*3,470,460+i*3,420,500+i*3,440,580+i*3,510,650+i*3,620,570+i*3};
		cleardevice();
		draw_earth(i*3,land1_points,land2_points);
		draw_rocket();
		if(i>5) draw_fire(i/10);
		delay(25-i/4);
	}

	//scene 2
	for(int i=0; i<=100; i++) {
		setbkcolor(COLOR(168-i*1.68,224-i*2.24,252-i*2.52));
		cleardevice();
		draw_rocket();
		draw_fire(i);
		draw_stars();
		delay(40);
	}

	//scene 3
	for(int i=0; i<=400; i++) {
		setbkcolor(BLACK);
		cleardevice();
		draw_rocket();
		draw_fire(i/5);
		draw_stars();
		draw_moon(i*2);
		delay(20);
	}

	getch();
	closegraph();
	return 0;
}
