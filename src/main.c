#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/drawing.h"
#include "../include/state.h"

void Display (void);
void Reshape (int, int);
void Timer(int value);

int main(int argc, char **argv) {

    InitState();
    ReadOptions(argc, argv);

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

void Display (void) {
    int width, height;
    time_t tm;
    struct tm *t_time;

    time(&tm);
    t_time = localtime(&tm);
    glClear(GL_COLOR_BUFFER_BIT);

    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);

    DrawClockHand(width, height, t_time);

    glFlush();
    // glutSwapBuffers();
}

void Reshape (int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScaled(1, -1, 1);
    glTranslated(0, -h, 0);
}

void Timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(500, Timer, 0);
}
