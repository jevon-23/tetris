#include "game_board.h"
#include "block.h"
#ifndef  LINE_H 
#define  LINE_H 

typedef struct block line_block;

line_block *make_line_block();
void rotate_line_block(game_board *board, line_block *l, bool direct);
bool place_line_block(game_board *board, line_block *l, int row, int col);
block *move_line_block(game_board *board, line_block *l, int row, int col);

#endif
