/*
Title: Implement DDA and Bresenham line drawing algorithm to draw: i)Simple
Line ii)Dashed Line iii)Dotted Line iv)Dash-Dotted line
Divide the screen in four quadrants with center as (0,0). The line should
work for all the slopes positive as well as negative.
*/

#include<GLUT/glut.h>
#include<iostream>
using namespace std;

int x1, x2, y1, y2, ch;

int getIncr (int diff)
{
    if (diff > 0) return 1;
    else if (diff < 0) return -1;
    else return 0;
}

bool getCondn(int ch, int i){
    switch (ch)
    {
        case 1: // Simple line
            return true;
        case 2: // Dashed line
            if (i % 16 <= 8) return true;
        case 3: // Dotted line
            if (i % 8 == 0) return true;
        case 4: // Dash-Dotted line
            if (i % 16 <= 4 || i % 16 == 10) return true;
    }
    return false;
}

void bresenhemAlgo(){
    int dy, dx, x, y, G, xIncr, yIncr, i;
    bool steep = false;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dy > dx) {
        steep = true; // m > 1
        // swap difference and point co-ordinates
        int temp = dx;
        dx = dy;
        dy = temp;
        temp = x1;
        x1 = y1;
        y1 = temp;
        temp = x2;
        x2 = y2;
        y2 = temp;
    }
    
    xIncr = getIncr(x2 - x1);
    yIncr = getIncr(y2 - y1);
    
    G = (2 * dy) - dx;
    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    
    for (i = 1; i <= dx; i++)
    {
        x += xIncr;
        if (G < 0) {
            G += 2 * dy;
        }
        else {
            y += yIncr;
            G += 2 * dy - 2 * dx;
        }
        if (getCondn(ch, i))
        {
            if (steep == false)
                glVertex2i(x, y);
            else
                glVertex2i(y, x);
        }
    }
    glEnd();
}


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
    for (i = 1; i <= steps; i++)
    {
        x = x + Xincr;
        y = y + Yincr;
        if (getCondn(ch, i))
        {
            glVertex2i(x, y);
        }
    }
    glEnd();
}


void initializeDisplay()
{
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

void display()
{
    initializeDisplay();
    ddaAlgo();
    bresenhemAlgo();
    glFlush();
}


int main(int argc, char **argv)
{
    cout << "Enter X1 and Y1" << endl;
    cin >> x1 >> y1;
    cout << "Enter X2 and Y2" << endl;
    cin >> x2 >> y2;
    cout << "1. Simple 2. Dashed 3. Dotted 4. Dash-Dotted" << endl;
    cout << "Enter your choice:" << endl;
    cin >> ch;
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

