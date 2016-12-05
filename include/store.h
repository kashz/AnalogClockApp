/*
 * store.h
 * @auther Shunta Karasawa
 */

#ifndef __STORE_H__
#define __STORE_H__

#include "./color.h"

struct _store {
    ColorRGB256 clockDialColor;
    ColorRGB256 clockHandColor;
    ColorRGB256 clockSecColor;
};
typedef struct _store Store;


extern Store store;

void InitStore();

#endif /* __STORE_H__ */
