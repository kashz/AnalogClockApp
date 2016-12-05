/*
 * state.c
 * @auther Shunta Karasawa
 */

#include "../include/state.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

State state;

void InitState() {
    state.mode = MODE_NORMAL;
    state.clockFaceType = CLOCK_DIAL_NORMAL;
}

void ReadOptions(int argc, char **argv) {
    int r;
    struct option longopt[] = {
        { "help"  , 0, NULL, 'h' },
        { "night" , 0, NULL, 'n' },
        { "all"   , 0, NULL, 'a' },
        { NULL    , 0, NULL, 0   }
    };
    opterr = 0;
    while (1) {
        r = getopt_long(argc, argv, "hna", longopt, NULL);
        if (r == -1) break;

        switch (r) {
            case 'h':
                printf(
                    "Usage: app [options] ...\n"
                    "Options:\n"
                    "\t-a, --all\t\tShow line of clock face on all time.\n"
                    "\t-h, --help\t\tPrint this message and exit.\n"
                    "\t-n, --night\t\tEnter night mode.\n"
                );
                exit(0);
                break;
            case 'n':
                printf("option night\n");
                state.mode = MODE_NIGHT;
                break;
            case 'a':
                state.clockFaceType = CLOCK_DIAL_ALL;
                break;
            case '?':
                printf("illegal option %s\n", argv[optind]);
                break;
            default:
                printf("getopt()が道\n");
                break;
        }
    }
    if (optind < argc) {
        printf("argvの中でオプションとして解釈されなかった引数があります:");
        while (optind < argc) {
            printf("%s ", argv[optind]);
            optind++;
        }
        printf("\n");
    }
}
