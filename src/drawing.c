/*
 * Drawing Functions
 * @auther Shunta Karasawa
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../include/type.h"
#include "../include/color.h"
#include "../include/drawing.h"
#include <math.h>

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

void DrawClockHand(int width, int height, struct tm *t_time) {
    Vector2i point;
    ColorRGB256 lineColor, secHandColor;
    int size, len;
    double theta;

    // Set Color
    lineColor.red = 62;
    lineColor.green = 63;
    lineColor.blue = 79;
    secHandColor.red = 239;
    secHandColor.green = 96;
    secHandColor.blue = 96;

    // Decide Size
    // Align to the smaller value.
    size = (width < height) ? (width/2*0.9) : (height/2*0.9);

    // Draw edge of clock
    SetColorRGB256(lineColor);
    DrawEllipseWithLine(width/2, height/2, size, size, 5);
    DrawEllipse(width/2, height/2, size * 0.08, size * 0.08);

    // Minutes
    theta = (2 * M_PI / 3600) * (double)(60 * t_time->tm_min + t_time->tm_sec);
    len = size * 0.9;
    point.x = width/2  + (double)len * sin(theta);
    point.y = height/2 - (double)len * cos(theta);
    SetColorRGB256(lineColor);
    glLineWidth(6);
    glBegin(GL_LINES);
    glVertex2i(width/2, height/2);
    glVertex2i(point.x, point.y);
    glEnd();

    // Hour
    theta = (2 * M_PI / 43200) * (double)(3600 * t_time->tm_hour + 60 * t_time->tm_min + t_time->tm_sec);
    len = size * 0.7;
    point.x = width/2  + (double)len * sin(theta);
    point.y = height/2 - (double)len * cos(theta);
    glLineWidth(6);
    glBegin(GL_LINES);
    glVertex2i(width/2, height/2);
    glVertex2i(point.x, point.y);
    glEnd();

    // Seconds
    len = size * 0.9;
    theta = (2*M_PI/60) * (double)(t_time->tm_sec);
    point.x = width/2  + (double)len * sin(theta);
    point.y = height/2 - (double)len * cos(theta);
    SetColorRGB256(secHandColor);
    DrawEllipse(width/2, height/2, size * 0.05, size * 0.05);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(width/2, height/2);
    glVertex2i(point.x, point.y);
    glEnd();
}
