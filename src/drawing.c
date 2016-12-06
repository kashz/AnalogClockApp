/*
 * drawing.c
 * @auther Shunta Karasawa
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../include/type.h"
#include "../include/state.h"
#include "../include/store.h"
#include "../include/color.h"
#include "../include/drawing.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of divisions for approximated polygons
#define POLYGON_ACCURACY 100

void DrawEllipse(int x, int y, int width, int height) {
    int i, n = POLYGON_ACCURACY;
    double rad;
    Vector2i point;

    glBegin(GL_POLYGON);
    for ( i = 0; i < n; i++ ) {
        rad = 2 * M_PI * ((double)i / n);
        point.x = x + width  * cos(rad);
        point.y = y + height * sin(rad);
        glVertex2i(point.x, point.y);
    }
    glEnd();
}
void DrawEllipseWithLine(int x, int y, int width, int height, float weight) {
    int i, n = POLYGON_ACCURACY;
    double rad;
    Vector2i point;
    float oldWeight;

    glGetFloatv(GL_LINE_WIDTH, &oldWeight);

    glLineWidth(weight);
    glBegin(GL_LINE_LOOP);
    for ( i = 0; i < n; i++ ) {
        rad = 2 * M_PI * ((double)i / n);
        point.x = x + width  * cos(rad);
        point.y = y + height * sin(rad);
        glVertex2i(point.x, point.y);
    }
    glEnd();

    // restore previous value
    glLineWidth(oldWeight);
}
void GetDayOfWeekChar(char* str, int wday) {
    switch (wday) {
        case 0:
            strcpy(str, "SUN");
            break;
        case 1:
            strcpy(str, "MON");
            break;
        case 2:
            strcpy(str, "TUE");
            break;
        case 3:
            strcpy(str, "WED");
            break;
        case 4:
            strcpy(str, "THU");
            break;
        case 5:
            strcpy(str, "FRI");
            break;
        case 6:
            strcpy(str, "SAT");
            break;
        default:
            strcpy(str, "");
            break;
    }
}

void DrawDate(struct tm *t_time) {
    char s[20];
    char wday[5];
    int i;

    GetDayOfWeekChar(wday, t_time->tm_wday);
    sprintf(s, "%d %3s", t_time->tm_mday, wday);

    glRasterPos2i(store.windowSize.x/2-(strlen(s)+1)*3, store.windowSize.y/2-9);
    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
    }
}

void DrawTime(struct tm *t_time) {
    char s[20];
    int i;

    sprintf(s, "%02d:%02d", t_time->tm_hour, t_time->tm_min);
    glRasterPos2i(store.windowSize.x/2-(strlen(s)+1)*4, store.windowSize.y/2+18);
    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }
}

void DrawClockHand(int len, float weight, double theta) {
    Vector2i point;

    point.x = store.windowSize.x/2 + (double)len * sin(theta);
    point.y = store.windowSize.y/2 - (double)len * cos(theta);
    glLineWidth(weight);
    glBegin(GL_LINES);
    glVertex2i(store.windowSize.x/2, store.windowSize.y/2);
    glVertex2i(point.x, point.y);
    glEnd();
}


void DrawSimpleClock(struct tm *t_time) {
    Vector2i point;
    int size, len;
    double theta, clockFaceIncrement;

    // Decide Size
    // Align to the smaller value.
    size = (store.windowSize.x < store.windowSize.y) ? (store.windowSize.x/2*0.9) : (store.windowSize.y/2*0.9);

    // Draw edge of clock
    SetGLColorRGB256(store.clockDialColor);
    DrawEllipseWithLine(store.windowSize.x/2, store.windowSize.y/2, size, size, 5);

    // Draw face of clock
    glLineWidth(6);
    glBegin(GL_LINES);
    clockFaceIncrement = (M_PI)/2;
    for ( theta = 0; theta < (2 * M_PI);theta += clockFaceIncrement ) {
        len = size * 0.9;
        point.x = store.windowSize.x/2  + (double)len * sin(theta);
        point.y = store.windowSize.y/2 - (double)len * cos(theta);
        glVertex2i(point.x, point.y);
        len = size;
        point.x = store.windowSize.x/2  + (double)len * sin(theta);
        point.y = store.windowSize.y/2 - (double)len * cos(theta);
        glVertex2i(point.x, point.y);
    }
    glEnd();


    SetGLColorRGB256(store.clockHandColor);
    // Minutes
    theta = (2 * M_PI / 3600) * (double)(60 * t_time->tm_min + t_time->tm_sec);
    len = size * 0.9;
    DrawClockHand(len, 5.5, theta);

    // Hour
    theta = (2 * M_PI / 43200) * (double)(3600 * t_time->tm_hour + 60 * t_time->tm_min + t_time->tm_sec);
    len = size * 0.7;
    DrawClockHand(len, 6, theta);
    DrawEllipse(store.windowSize.x/2, store.windowSize.y/2, size * 0.08, size * 0.08);

    // Seconds
    SetGLColorRGB256(store.clockSecColor);
    len = size * 0.9;
    theta = (2*M_PI/60) * (double)(t_time->tm_sec);
    DrawClockHand(len, 3, theta);
    DrawEllipse(store.windowSize.x/2, store.windowSize.y/2, size * 0.05, size * 0.05);
}

void DrawAnalogClock(struct tm *t_time) {
    Vector2i point;
    int size, len, cnt = 0;
    int i, afterSec;
    double theta, clockFaceIncrement;
    ColorRGBA256 afterColor = ConvertToRGBA256(store.clockSecColor, 255);

    // Decide Size
    // Align to the smaller value.
    size = (store.windowSize.x < store.windowSize.y) ? (store.windowSize.x/2*0.9) : (store.windowSize.y/2*0.9);

    // Clear
    glClearColor(store.bgColor.red/255.0, store.bgColor.green/255.0, store.bgColor.blue/255.0, 1.0);

    // Draw edge of clock
    SetGLColorRGB256(store.clockDialColor);
    DrawEllipseWithLine(store.windowSize.x/2, store.windowSize.y/2, size, size, 5);
    clockFaceIncrement = (M_PI)/30;
    for ( theta = 0; theta < (2 * M_PI); theta += clockFaceIncrement ) {
        if (cnt % 5 == 0) {
            glLineWidth(3);
            len = size * 0.95;
        } else {
            glLineWidth(1);
            len = size * 0.93;
        }
        glBegin(GL_LINES);
        point.x = store.windowSize.x/2  + (double)len * sin(theta);
        point.y = store.windowSize.y/2 - (double)len * cos(theta);
        glVertex2i(store.windowSize.x/2, store.windowSize.y/2);
        glVertex2i(point.x, point.y);
        glEnd();
        cnt++;
    }

    // Afterimage of Color
    for (i = 1; i < 20; i++) {
        afterSec = t_time->tm_sec - i;
        if (afterSec < 0) {
            afterSec += 60;
        }
        theta = (M_PI/30) * (double)(afterSec);
        glColor4ub(afterColor.red, afterColor.green, afterColor.blue, afterColor.alpha-i*(255)/(20));
        if (afterSec % 5 == 0) {
            len = size * 0.95;
            DrawClockHand(len, 3, theta);
        } else {
            len = size * 0.93;
            DrawClockHand(len, 1, theta);
        }
    }

    SetGLColorRGB256(store.bgColor);
    DrawEllipse(store.windowSize.x/2, store.windowSize.y/2, size/1.6, size/1.6);

    // Draw Clock Hand
    SetGLColorRGB256(store.clockHandColor);
    // Minutes
    theta = (2 * M_PI / 3600) * (double)(60 * t_time->tm_min + t_time->tm_sec);
    len = size * 0.95;
    DrawClockHand(len, 8, theta);

    // Hour
    theta = (2 * M_PI / 43200) * (double)(3600 * t_time->tm_hour + 60 * t_time->tm_min + t_time->tm_sec);
    len = size * 0.7;
    DrawClockHand(len, 8, theta);
    DrawEllipse(store.windowSize.x/2, store.windowSize.y/2, size * 0.08, size * 0.08);

    // Seconds
    SetGLColorRGB256(store.clockSecColor);
    len = size * 0.95;
    theta = (2*M_PI/60) * (double)(t_time->tm_sec);
    DrawClockHand(len, 3, theta);
    DrawEllipse(store.windowSize.x/2, store.windowSize.y/2, size * 0.05, size * 0.05);


    SetGLColorRGB256(store.bgColor);
    DrawEllipse(store.windowSize.x/2, store.windowSize.y/2, size/4, size/4);

    // Write Day and Time
    SetGLColorRGB256(store.textColor);
    DrawDate(t_time);
    DrawTime(t_time);
}
