#include "block.h"
#ifndef  EMPTY_H 
#define  EMPTY_H 


typedef struct block empty_block;
//typedef struct empty_block {
//    block *blok;
//} empty_block;

empty_block *make_empty_block();
empty_block rotate_empty_block();

#endif
