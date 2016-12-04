#ifndef __STATE_H__
#define __STATE_H__
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct _state {
    int mode;
};
typedef struct _state State;

#define MODE_NORMAL (1)
#define MODE_NIGHT  (2)

extern State state;

void InitState();
void ReadOptions(int argc, char **argv);

#endif /* __STATE_H__ */
