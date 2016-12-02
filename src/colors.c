#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../include/colors.h"

ColorRGB ConvertRGB(ColorRGB256 col)
{
    ColorRGB col1;
    col1.red = col.red / 255;
    col1.green = col.green / 255;
    col1.blue = col.blue / 255;

    return col1;
}
void SetColorRGB256(ColorRGB256 col)
{
    ColorRGB color;
    color = ConvertRGB(col);
    glColor3d(color.red, color.green, color.blue);
}
