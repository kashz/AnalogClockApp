#ifndef __STATE_H__
#define __STATE_H__
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

struct _state {
    int mode;
    int clockFaceType;
};
typedef struct _state State;

#define MODE_NORMAL (0)
#define MODE_NIGHT  (1)

#define CLOCK_FACE_NORMAL (0)
#define CLOCK_FACE_ALL    (1)

extern State state;

void InitState();
void ReadOptions(int argc, char **argv);

#endif /* __STATE_H__ */
