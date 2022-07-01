#include "game_board.h"
#ifndef  Z_H 
#define  Z_H 

typedef struct z_block {
    block *blok;
} z_block;

z_block make_z_block();
z_block rotate_z_block();
#endif
