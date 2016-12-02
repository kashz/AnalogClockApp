#include "../include/type.h"
#include "../include/drawing.h"
#include <math.h>

void DrawEllipse(int x, int y, int width, int height) {
    int i, n = 25;
    double rad;
    Vector2d point;

    glBegin(GL_POLYGON);
    for ( i = 0; i < part; i++ ) {
        rad = 2 * M_PI * ((double)i / n);
        point.x = width  * cos(rad);
        point.y = height * sin(rad);
        glVertex2i(point.x, point.y);
    }
    glEnd();
}

void DrawClockHand()
{

}
