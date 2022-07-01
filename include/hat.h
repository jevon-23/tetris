#include "block.h"
#ifndef  HAT_H 
#define  HAT_H 

typedef struct hat_block {
    block *blok;
} hat_block;

hat_block make_hat_block();
hat_block rotate_hat_block();
#endif
