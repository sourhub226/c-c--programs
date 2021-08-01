//To implement the 2D transformation on a polygon.
#include<graphics.h>
#include<iostream>
using namespace std;

int poly_sides=3;
int polygon[]= {400,200,400,300,200,300};
int transformed_polygon[]= {};

void display_text(char *top_str1,char *top_str2) {
	cleardevice();
	setcolor(WHITE);
	outtextxy(10,10,top_str1);
	outtextxy(10,20,top_str2);
	outtextxy(300,getmaxy()-10,"Press any key to proceed...");
	outtextxy(700,10,"Original");
	line(640,15,690,15);
	outtextxy(700,20,"Transformed");
	setcolor(RED);
	line(640,25,690,25);
}

void draw_polygon(int arr[],int color) {
	setcolor(color);
	drawpoly(poly_sides,arr);
}

void translate2D(float tx,float ty) {
	for(int i=0; i<2*poly_sides; i+=2) {
		transformed_polygon[i]=polygon[i]+tx;
		transformed_polygon[i+1]=polygon[i+1]+ty;
	}
}

void rotate2D(float theta){
	for(int i=0; i<2*poly_sides; i+=2) {
		transformed_polygon[i]=polygon[i]*cos(theta)-polygon[i+1]*sin(theta);
		transformed_polygon[i+1]=polygon[i]*sin(theta)+polygon[i+1]*cos(theta);
	}
}

void scale2D(float sx,float sy) {
	for(int i=0; i<2*poly_sides; i+=2) {
		transformed_polygon[i]=polygon[i]*sx;
		transformed_polygon[i+1]=polygon[i+1]*sy;
	}
}

void reflectY2D(int offsetx) {
	for(int i=0; i<2*poly_sides; i+=2) {
		transformed_polygon[i]=-polygon[i]+2*offsetx;
		transformed_polygon[i+1]=polygon[i+1];
	}
}

void shear2D(float shx,float shy) {
	for(int i=0; i<2*poly_sides; i+=2) {
		transformed_polygon[i]=polygon[i]+shx*polygon[i+1];
		transformed_polygon[i+1]=polygon[i+1]+shy*polygon[i];
	}
}

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	sdlbgiauto();
	char buffer [50];

	//translation w.r.t origin
	float tx=100,ty=100;
	sprintf(buffer, "tx = %.2f, ty = %.2f", tx,ty);
	display_text("Translation",buffer);
	draw_polygon(polygon,WHITE);
	translate2D(tx,ty);
	draw_polygon(transformed_polygon,RED);
	getch();

	//Rotation w.r.t origin
	float theta=10;
	sprintf(buffer, "theta = %.2f deg",theta);
	display_text("Rotation",buffer);
	draw_polygon(polygon,WHITE);
	rotate2D(theta*3.14/180);
	draw_polygon(transformed_polygon,RED);
	getch();

	//Scaling w.r.t origin
	float sx=1.5,sy=1.5;
	sprintf(buffer, "sx = %.2f, sy = %.2f", sx,sy);
	display_text("Scaling",buffer);
	draw_polygon(polygon,WHITE);
	scale2D(sx,sy);
	draw_polygon(transformed_polygon,RED);
	getch();

	//Reflection w.r.t arbitrary y axis (for displaying proper output in the window)
	int offsetx=420;
	sprintf(buffer, "along arbitrary y axis at x=%d", offsetx);
	display_text("Reflection",buffer);
	draw_polygon(polygon,WHITE);
	line(offsetx,50,offsetx,getmaxy()-50);
	reflectY2D(offsetx);
	draw_polygon(transformed_polygon,RED);
	getch();

	//Shearing w.r.t origin
	float shx=0.2,shy=0.1;
	sprintf(buffer, "shx = %.2f, shy = %.2f", shx,shy);
	display_text("Shearing",buffer);
	draw_polygon(polygon,WHITE);
	shear2D(shx,shy);
	draw_polygon(transformed_polygon,RED);
	getch();

	closegraph();
}
