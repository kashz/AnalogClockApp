/*
 * store.c
 * @auther Shunta Karasawa
 */

#include "../include/store.h"


// Global store
Store store;

void InitStore() {
    store.clockDialColor = SetColorRGB256(62, 63, 79);
    store.clockHandColor = store.clockDialColor;
    store.clockSecColor  = SetColorRGB256(239, 96, 96);
}
