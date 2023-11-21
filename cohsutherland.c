#include <stdio.h>
#include <graphics.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin, ymin, xmax, ymax; 
int x1 = 50, y1 = 50, x2 = 200, y2 = 200;

int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}


void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1, code2, code;
    int accept = 0, done = 0;

    while (!done) {
        code1 = computeCode(x1, y1);
        code2 = computeCode(x2, y2);

        
        if (code1 == 0 && code2 == 0) {
            accept = 1;
            done = 1;
        }
        
        else if (code1 & code2) {
            done = 1;
        }
        
        else {
            int x, y;

            code = (code1 != 0) ? code1 : code2;

            if (code & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code == code1) {
                x1 = x;
                y1 = y;
            } else {
                x2 = x;
                y2 = y;
            }
        }
    }

    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    
    // printf("Enter xmin");
    // scanf("%d", &xmin);

    // printf("Enter ymin");  
    // scanf("%d", &ymin);
    
    // printf("Enter xmax");  
    // scanf("%d", &xmax);
    
    // printf("Enter ymax");  
    // scanf("%d", &ymax);

    // printf("Enter co-ordinates of first point: ");  
    // scanf("%d%d", &x1, &y1);  
    // printf("Enter co-ordinates of second point: ");  
    // scanf("%d%d", &x2, &y2);  



    xmin = 100;
    ymin = 100;
    xmax = 300;
    ymax = 300;

    rectangle(xmin, ymin, xmax, ymax);

    setcolor(BLUE);
    line(x1, y1, x2, y2);

    cohenSutherland(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}