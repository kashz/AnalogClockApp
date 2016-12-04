/*
 * type.h
 * @auther Shunta Karasawa
 */

#ifndef __TYPE_H__
#define __TYPE_H__

struct _vector2_int {
    int x;
    int y;
};

struct _vector2_double {
    double x;
    double y;
};

typedef struct _vector2_int Vector2i;
typedef struct _vector2_double Vector2d;

#endif /* __TYPE_H__ */
