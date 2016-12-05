/*
 * drawing.h
 * @auther Shunta Karasawa
 */

#ifndef __DRAWING_H__
#define __DRAWING_H__

#include <time.h>

void DrawEllipse(int x, int y, int width, int height);
void DrawEllipseWithLine(int x, int y, int width, int height, float weight);

void GetDayOfWeekChar(char* str, int wday);

void DrawDate(struct tm *t_time);
void DrawTime(struct tm *t_time);

void DrawClockHand(int length, float weight, double theta);

void DrawSimpleClock(struct tm *t_time);
void DrawAnalogClock(struct tm *t_time);

#endif /* __DRAWING_H__ */
