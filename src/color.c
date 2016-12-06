/*
 * color.c
 * @auther Shunta Karasawa
 */

#include "../include/color.h"

ColorRGB256 SetColorRGB256(int red, int green, int blue) {
    ColorRGB256 color;

    if (red < 256 && red >= 0) {
        color.red = red;
    } else {
        color.red = 0;
    }
    if (green < 256 && green >= 0) {
        color.green = green;
    } else {
        color.green = 0;
    }
    if (blue < 256 && blue >= 0) {
        color.blue = blue;
    } else {
        color.blue = 0;
    }
    return color;
}
ColorRGBA256 SetColorRGBA256(int red, int green, int blue, int alpha) {
    ColorRGBA256 color;

    if (red < 256 && red >= 0) {
        color.red = red;
    } else {
        color.red = 0;
    }
    if (green < 256 && green >= 0) {
        color.green = green;
    } else {
        color.green = 0;
    }
    if (blue < 256 && blue >= 0) {
        color.blue = blue;
    } else {
        color.blue = 0;
    }
    if (alpha < 256 && alpha >= 0) {
        color.alpha = alpha;
    } else {
        color.alpha = 0;
    }
    return color;
}
ColorRGBA256 ConvertToRGBA256(ColorRGB256 col, int alpha) {
    return SetColorRGBA256(col.red, col.green, col.blue, alpha);
}

void SetGLColorRGB256(ColorRGB256 col) {
    glColor3ub(col.red, col.green, col.blue);
}

void SetGLColorRGBA256(ColorRGBA256 col) {
    glColor4ub(col.red, col.green, col.blue, col.alpha);
}
