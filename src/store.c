/*
 * store.c
 * @auther Shunta Karasawa
 */

#include "../include/store.h"


// Global store
Store store;

void InitStore() {
    store.clockSecColor  = SetColorRGB256(239, 96, 96);
    store.windowSize.x = 300;
    store.windowSize.x = 300;
}
