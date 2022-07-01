#include "block.h"
#ifndef  LINE_H 
#define  LINE_H 

typedef struct line_block {
    block *blok;
} line_block;

line_block make_line_block();
line_block rotate_line_block(line_block *l);

#endif
