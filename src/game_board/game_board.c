#include "../../include/empty.h"
#include "../../include/line.h"
#include "../../include/game_board.h"
#include "../../include/block.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

void rotate_block(game_board *board, block *b) {
    if (b->typ == EMPTY) {
      printf("invalid block type to rotate \n");
      exit(-1);
    }
    b->rotate_block(board, b, true);

}

block *get_block(game_board *board, int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return NULL;
    }
    return (*(board->board + row) + col);

}
void free_group(game_board *board, block *blok) {
    /* First, change all of the blocks to empty blocks */
    for (int i = 0; i < 4; i++) {
        empty_block *e = (empty_block *)make_block(EMPTY);
        place_block(board, e, blok->group[i].rows, blok->group[i].cols);
    }
}

void free_block_group(game_board *board, block *blok) {
    free_group(board, blok);
    free(blok);

}

/* Make sure that we are trying to move an active block */
void is_active(block *b) {
    if (!b->active) {
        printf("block is inactive: trying to move a block that is not moveable\n");
        printf("block pos: (%d, %d)", b->row_pos, b->col_pos);
        exit(-1);
    }
}

/* Place a block on the game board @ the top and in the middle. */
bool place_block(game_board *board, block *blok, int row, int col) {
    blok->row_pos = row;
    blok->col_pos = col;
    bool out = blok->place_block(board, blok, row, col);
    blok->active = true;
    return out;
}


/* Move a block one unit to the right */
block *move_block_left(game_board *board, block *blok) {
    is_active(blok);

    if (blok->col_pos + blok->dim.cols - 1 < 0)
        return blok;

    return blok->move_block(board, blok, blok->row_pos, blok->col_pos-1);


}

/* Move a block one unit to the right */
block *move_block_right(game_board *board, block *blok) {
    is_active(blok);

    /* If we are at a boundary, just return the block */
    if (blok->col_pos + blok->dim.cols + 1 > COLS)
        return blok;

    return blok->move_block(board, blok, blok->row_pos, blok->col_pos+1);

}

/* Move a block one unit down */
block *move_block_down(game_board *board, block *blok) {
    is_active(blok);


    if (blok->row_pos + blok->dim.rows + 1 > ROWS)
        return NULL;

    return blok->move_block(board, blok, blok->row_pos+1, blok->col_pos);

}
/* Generates the gameboard */
game_board *make_game_board() {
    game_board *gb = malloc(sizeof(game_board));
    gb->rows = ROWS;
    gb->cols = COLS;

    /* Malloc space for actual game board, and make each block empty */
    gb->board = (block **) malloc(sizeof(block) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        *(gb->board + i) = malloc(sizeof(block) * COLS);

        for (int j = 0; j < COLS; j++) {
            /* Make an empty block and write it to game_board */
            empty_block *e = make_block(EMPTY);
            place_block(gb, e, i, j);
        }
    }
    return gb;
}

/* Resets the gameboard */
bool reset_game_board();

/* Prints out the gameboard */
void print_game_board(game_board *gb) {
    for (int row = 0; row < ROWS; row++) {
        printf("|");
        for (int col = 0; col < COLS; col++) {
            printf("%c|", (*(gb->board + row) + col)->typ);
        }
        printf("\n");
    }
    printf("\n");

}

