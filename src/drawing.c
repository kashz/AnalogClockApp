#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../include/type.h"
#include "../include/colors.h"
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

void DrawClockHand()
{

}
