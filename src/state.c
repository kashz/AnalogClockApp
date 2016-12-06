/*
 * state.c
 * @auther Shunta Karasawa
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "../include/state.h"
#include "../include/store.h"
#include "../include/color.h"

State state;

void InitState() {
    EnterNormalMode();
    EnterFancyType();
}

void ReadOptions(int argc, char **argv) {
    int r;
    struct option longopt[] = {
        { "help"  , 0, NULL, 'h' },
        { "night" , 0, NULL, 'n' },
        { "simple", 0, NULL, 's' },
        { NULL    , 0, NULL, 0   }
    };
    opterr = 0;
    while (1) {
        r = getopt_long(argc, argv, "hns", longopt, NULL);
        if (r == -1) break;

        switch (r) {
            case 'h':
                printf(
                    "Usage: app [options] ...\n"
                    "Options:\n"
                    "\t-h, --help\t\tPrint this message and exit\n"
                    "\t-n, --night\t\tEnter night mode\n"
                    "\t-s, --simple\t\tUse simple clock\n"
                );
                exit(0);
                break;
            case 'n':
                printf("option night\n");
                EnterNightMode();
                break;
            case 's':
                EnterSimpleType();
                break;
            case '?':
                printf("illegal option\nTry `clock --help\'");
                exit(0);
                break;
            default:
                printf("unknown error\n");
                break;
        }
    }
}
void EnterFancyType() {
    state.clockType = CLOCK_TYPE_FANCY;
    store.clockDialColor = SetColorRGB256(160, 160, 160);
}
void EnterSimpleType() {
    state.clockType = CLOCK_TYPE_SIMPLE;
    store.clockDialColor = SetColorRGB256(62, 63, 85);
}
void EnterNormalMode() {
    state.mode = MODE_NORMAL;
    store.clockHandColor = SetColorRGB256(62, 63, 85);
    store.clockDialColor = SetColorRGB256(220, 220, 220);
    store.textColor = SetColorRGB256(40, 40, 40);
    store.bgColor = SetColorRGB256(240, 240, 240);
}
void EnterNightMode() {
    state.mode = MODE_NIGHT;
    store.clockDialColor = SetColorRGB256(62, 63, 85);
    store.clockHandColor = SetColorRGB256(150, 150, 150);
    store.textColor = SetColorRGB256(220, 220, 220);
    store.bgColor = SetColorRGB256(40, 40, 40);
}
