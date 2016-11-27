#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h>

void Display (void);
void Reshape (int, int);
void Timer(int value);
void Write(int sec, int min, int hour, int w, int h);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Clock");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(500, Timer, 0);

    glutInitDisplayMode(GLUT_RGBA);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();

    return 0;
}

void Display (void)
{
    int width, height;
    time_t tm;
    struct tm *t_time;

    time(&tm);
    t_time = localtime(&tm);
    glClear(GL_COLOR_BUFFER_BIT);

    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);

    Write(t_time->tm_sec, t_time->tm_min, t_time->tm_hour, width, height);

    glFlush();
    // glutSwapBuffers();
}

void Reshape (int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScaled(1, -1, 1);
    glTranslated(0, -h, 0);
}

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(500, Timer, 0);
}
void Write(int sec, int min, int hour, int w, int h)
{
    int x, y;
    double theta;
    int xc = w/2;
    int yc = h/2;
    int l = 100;

    // Seconds
    theta = (2*M_PI/60) * (double)sec;
    x = (double)xc + (double)l*sin(theta);
    y = (double)yc - (double)l*cos(theta);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(xc, yc);
    glVertex2i(x, y);
    glEnd();

    // Minutes
    theta = (2*M_PI/3600) * (double)(60*min+sec);
    l = 100;
    x = (double)xc + (double)l*sin(theta);
    y = (double)yc - (double)l*cos(theta);
    glBegin(GL_LINES);
    glColor3ub(1, 0, 0);
    glVertex2i(xc, yc);
    glVertex2i(x, y);
    glEnd();

    // Hour
    theta = (2*M_PI/43200) * (double)(3600*hour + 60*min+sec);
    l = 80;
    x = (double)xc + (double)l*sin(theta);
    y = (double)yc - (double)l*cos(theta);
    glBegin(GL_LINES);
    glColor3ub(0, 1, 0);
    glVertex2i(xc, yc);
    glVertex2i(x, y);
    glEnd();
}
