#include "game_board.h"
#include "block.h"
#ifndef  LINE_H 
#define  LINE_H 

typedef struct block line_block;

line_block *make_line_block();
void rotate_line_block(line_block *l);
void draw_line_block(game_board *board, line_block *blok);

#endif
