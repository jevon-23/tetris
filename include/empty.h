/*
 * EMPTY BLOCKS                   
 */
#include "game_board.h"
#include "block.h"
#ifndef  EMPTY_H 
#define  EMPTY_H 

/* Empty block, denoted as '_' on the gameboard. Is used if 
 * filled an entire row or setting up the game, etc. 
 */
typedef struct block empty_block;

/* Allocates a new empty block, and returns a pointer to it */
empty_block *make_empty_block();

bool place_empty_block(game_board *board, empty_block *e, int row, int col);

#endif
