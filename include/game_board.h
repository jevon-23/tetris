#include "block.h"
#include <stdbool.h>
#ifndef  GAME_BOARD_H 
#define  GAME_BOARD_H 

/* Board size */
#define ROWS 20
#define COLS 10

typedef struct game_board {
    int rows; /* Rows in game_board */
    int cols; /* Cols in game_board */
    block **board; /* Pointer to the board */
    block *current_block; /* current block in play */
    block **next_blocks; /* next blocks */
} game_board;

extern int points;

/* Get a block at coords (row, col) */
block *get_block(game_board *board, int row, int col);

/* Rotate the current block in play */
void rotate_block(game_board *board, block *b);

/* Change all of the blocks in BLOK's group to empty blocks ; doesn't free block */
void free_group(game_board *board, block *blok);

/* Change all of the blocks in BLOK's group to empty blocks and free block */
void free_block_group(game_board *board, block *blok);

/* Place BLOK into coords (row, col) */
void place_block(game_board *board, block *blok, int row, int col);

/* Print the game boards current state */
void print_game_board(game_board *board);

/* Move the current block in play down by 1 block  */
block *move_block_down(game_board *board, block *blok);

/* Move the current block in play to the right by 1 */
void move_block_right(char **game_board);

/* Move the current block in play to the left by 1 */
void move_block_left(char **game_board);

/* Make a new game board */
game_board *make_game_board();
void update_game_board();
bool game_over();

#endif
