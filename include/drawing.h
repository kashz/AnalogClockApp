/*
 * drawing.h
 * @auther Shunta Karasawa
 */

#ifndef __DRAWING_H__
#define __DRAWING_H__

#include <time.h>

void DrawEllipse(int x, int y, int width, int height);
void DrawEllipseWithLine(int x, int y, int width, int height, float weight);

void DrawClock(int width, int height, struct tm *t_time);

#endif /* __DRAWING_H__ */
