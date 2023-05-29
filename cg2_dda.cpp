/*
Title: Implement DDA and Bresenham line drawing algorithm to draw: i) Simple
Line ii) Dashed Line iii) Dotted Line iv) Dash-Dotted Line ;
Divide the screen in four quadrants with center as (0,0). The line should
work for all the slopes positive as well as negative.
 
Digital Differential Analyzer
 
*/

#include<GLUT/glut.h>
#include<iostream>
using namespace std;

float x1, x2, y1, y2;
int ch;


void ddaAlgo(){
    float dy, dx, steps, x, y, Xincr, Yincr;
    int i;

    dx = x2 - x1;
    dy = y2 - y1;
    
    steps = max(abs(dx), abs(dy));
    
    Xincr = dx / steps;
    Yincr = dy / steps;
    
    x = x1;
    y = y1;
    
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    
    switch (ch)
    {
        case 1:
            // Simple line
            for (i = 1; i <= steps; i++)
            {
                x = x + Xincr;
                y = y + Yincr;
                glVertex2i(x, y);
            }
            break;
        case 2:
            // Dashed line
            for (i = 1; i <= steps; i++)
            {
                x = x + Xincr;
                y = y + Yincr;
                if (i % 16 <= 8)
                {
                    glVertex2i(x, y);
                }
            }
            break;
        case 3:
            // Dotted Line
            for (i = 1; i <= steps; i++)
            {
                x = x + Xincr;
                y = y + Yincr;
                if (i % 8 == 0)
                {
                    glVertex2i(x, y);
                }
            }
            break;
        case 4:
            // Dash-Dotted Line
            for (i = 1; i <= steps; i++)
            {
                x = x + Xincr;
                y = y + Yincr;
                if (i % 16 <= 4 || i % 16 == 10)
                {
                    glVertex2i(x, y);
                }
            }
            break;
    }
    glEnd();
}

void initializeDisplay(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    gluOrtho2D(-500, 500, -500, 500);
    glLineWidth(5);
    
    glBegin(GL_LINES);
    glVertex2i(-500, 0);
    glVertex2i(500, 0);
    glVertex2i(0, -500);
    glVertex2i(0, 500);
    glEnd();
}

void display(void)
{
    initializeDisplay();
    ddaAlgo();
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter X1 and Y1" << endl;
    cin >> x1 >> y1;
    cout << "Enter X2 and Y2" << endl;
    cin >> x2 >> y2;
    cout << "1.Simple 2.Dashed 3.Dotted 4.Dash-Dotted" << endl;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    
    // x1 = 0, y1 = 0; x2 = 500, y2 = 500, ch = 4;
    
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

