/*
 * color.h
 * @auther Shunta Karasawa
 */

#ifndef __COLOR_H__
#define __COLOR_H__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


// 0 - 255
struct _rgb256 {
    int red;
    int green;
    int blue;
};
typedef struct _rgb256 ColorRGB256;

struct _rgba256 {
    int red;
    int green;
    int blue;
    int alpha;
};
typedef struct _rgba256 ColorRGBA256;

ColorRGB256 SetColorRGB256(int red, int green, int blue);
ColorRGBA256 SetColorRGBA256(int red, int green, int blue, int alpha);
ColorRGBA256 ConvertToRGBA256(ColorRGB256 col, int alpha);
void SetGLColorRGB256(ColorRGB256 col);
void SetGLColorRGBA256(ColorRGBA256 col);

#endif /* __COLOR_H__ */
