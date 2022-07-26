#include "game_board.h"
#include "block.h"

#ifndef  SQUARE_H 
#define  SQUARE_H 

typedef struct block square_block;

square_block *make_square();
void rotate_square_block(game_board *board, square_block *s, bool direct);
bool place_square(game_board *board, square_block *s, int row, int col);
block *move_square(game_board *board, square_block *s, int row, int col);

/* do not need a rotate square */
#endif
