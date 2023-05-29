#include <GLUT/glut.h>

void display(void)
{
    glClearColor(0.8, 0.8, 0.9, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(0.0, 0.0);
    glColor3f(0.0, 1.0, 1.0); glVertex2f(0.9, 0.0);
    glColor3f(1.0, 1.0, 0.0); glVertex2f(0.9, -0.9);
    glColor3f(0.4, 0.5, 0.6); glVertex2f(0.0, -0.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.0); glVertex2f(0.0, 0.0);
    glColor3f(0.5, 0.0, 0.2); glVertex2f(0.9, 0.0);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(0.45, 0.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0); glVertex2f(0.3, -0.5);
    glColor3f(0.0, 0.0, 0.0); glVertex2f(0.6, -0.5);
    glColor3f(0.0, 0.0, 0.0); glVertex2f(0.6, -0.9);
    glColor3f(0.0, 0.0, 0.0); glVertex2f(0.3, -0.9);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("HOME");

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
