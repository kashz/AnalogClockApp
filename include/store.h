/*
 * store.h
 * @auther Shunta Karasawa
 */

#ifndef __STORE_H__
#define __STORE_H__

#include "./color.h"
#include "./type.h"

struct _store {
    ColorRGB256 clockDialColor;
    ColorRGB256 clockHandColor;
    ColorRGB256 clockSecColor;
    ColorRGB256 textColor;
    ColorRGB256 bgColor;
    Vector2i windowSize;
};
typedef struct _store Store;


extern Store store;

void InitStore();

#endif /* __STORE_H__ */
