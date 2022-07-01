#include "block.h"
#include <stdbool.h>
#ifndef  L_H 
#define  L_H 
typedef struct l_block {
    block *blok;
    bool L_or_R; /* 0 == L, 1 == R */
} l_block;

l_block make_left_l_block();
l_block make_right_l_block();
l_block rotate_left_l_block();
l_block rotate_right_l_block();
#endif
