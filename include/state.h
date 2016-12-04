#ifndef __STATE_H__
#define __STATE_H__

struct _state {
    int mode;
};
typedef struct _state State;

#define MODE_NORMAL (1)
#define MODE_NIGHT  (2)

void InitState();
extern State state;

#endif /* __STATE_H__ */
