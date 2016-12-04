#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../include/color.h"

ColorRGB ConvertRGB(ColorRGB256 col256)
{
    ColorRGB col;
    col.red   = (double)col256.red   / 255;
    col.green = (double)col256.green / 255;
    col.blue  = (double)col256.blue  / 255;

    return col;
}
void SetColorRGB256(ColorRGB256 col256)
{
    ColorRGB col;
    col = ConvertRGB(col256);
    glColor3d(col.red, col.green, col.blue);
}
