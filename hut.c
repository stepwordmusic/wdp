#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
	int gd= DETECT;
	int gm = gm;
	char data[] = "C:\\TURBOC3\\BGI";
	initgraph(&gd,&gm, data);
	rectangle(180,200,450,420);
	line(160,200,315,100);
	line(470,200,315,100);
	rectangle(200,420,280,320);
	rectangle(220,380,260,340);
	rectangle(220,360,240,340);
	rectangle(240,380,260,340);
	rectangle(240,360,260,340);
	line(160,200,470,200);
    circle(212,390,5);
	getch();
	closegraph();
	return 0;
}
