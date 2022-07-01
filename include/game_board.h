#include "block.h"
#include <stdbool.h>
#ifndef  GAME_BOARD_H 
#define  GAME_BOARD_H 

/* Board size */
#define ROWS 20
#define COLS 10

typedef struct game_board {
    int rows;
    int cols;
    block **board;
    block *current_block;
    block **next_blocks;
} game_board;

extern int points;

game_board *make_game_board();
bool place_block(game_board *board, block *blok, int row, int col);
void print_game_board(game_board *board);
bool store_block(char **game_board, block blok);
void move_block_down(char **game_board);
void move_block_right(char **game_board);
void move_block_left(char **game_board);
void update_game_board();
bool game_over();

#endif
