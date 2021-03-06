/*
 * main.c
 * @auther Shunta Karasawa
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/drawing.h"
#include "../include/state.h"
#include "../include/store.h"

void Display (void);
void Reshape (int, int);
void Timer (int value);
void Keyboard(unsigned char key, int x, int y);

int main(int argc, char **argv) {

    InitStore();
    InitState();
    ReadOptions(argc, argv);

    glutInit(&argc, argv);
    glutInitWindowSize(store.windowSize.x, store.windowSize.y);
    glutCreateWindow("Awesome Clock");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(500, Timer, 0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutInitDisplayMode(GLUT_RGBA);
    glClearColor(store.bgColor.red/255.0, store.bgColor.green/255.0, store.bgColor.blue/255.0, 1.0);

    glutMainLoop();

    return 0;
}

void Display (void) {
    time_t tm;
    struct tm *t_time;

    time(&tm);
    t_time = localtime(&tm);
    glClear(GL_COLOR_BUFFER_BIT);

    // update window size in store
    store.windowSize.x = glutGet(GLUT_WINDOW_WIDTH);
    store.windowSize.y = glutGet(GLUT_WINDOW_HEIGHT);

    if (state.clockType == CLOCK_TYPE_SIMPLE)
        DrawSimpleClock(t_time);
    else if (state.clockType == CLOCK_TYPE_FANCY)
        DrawAnalogClock(t_time);
    glFlush();
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

void Keyboard(unsigned char key, int x, int y) {
    if (key == 'q' || key == 27) {
        printf("exit...\n");
        exit(0);
    }
    if (key == 'm') {
        if (state.mode == MODE_NIGHT) {
            EnterNormalMode();
        }
        else if (state.mode == MODE_NORMAL) {
            EnterNightMode();
        }
        glClearColor(store.bgColor.red/255.0, store.bgColor.green/255.0, store.bgColor.blue/255.0, 1.0);
    }
    if (key == 't') {
        if (state.clockType == CLOCK_TYPE_SIMPLE) {
            EnterFancyType();
        }
        else if (state.clockType == CLOCK_TYPE_FANCY){
            EnterSimpleType();
        }
        glClearColor(store.bgColor.red/255.0, store.bgColor.green/255.0, store.bgColor.blue/255.0, 1.0);
    }
}
