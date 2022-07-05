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
    switch (b->typ) {
        case LINE:
            rotate_line_block(board, (line_block *)b);
            break;

        default:
            printf("invalid block type to rotate \n");
            exit(-1);
    }

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
        *(*(board->board + blok->group[i].rows)+ blok->group[i].cols) =*e;
        free(e);
    }
}

void free_block_group(game_board *board, block *blok) {
    free_group(board, blok);
    free(blok);

}

/* Place a block on the game board @ the top and in the middle. */
void place_block(game_board *board, block *blok, int row, int col) {
    blok->row_pos = row;
    blok->col_pos = col;
    switch (blok->typ) {
        case EMPTY:
            place_empty_block(board, (empty_block *)blok, row, col);
            break;
        case LINE:
            place_line_block(board, (line_block *)blok, row, col);
            break;
        default:
            printf("not a type of block that we can place\n");
            exit(-1);
    }
    blok->active = true;
    return;
}

block *move_block_down(game_board *board, block *blok) {
    /* Make sure that we are trying to move an active block */
    if (!blok->active) {
        printf("block is inactive: trying to move a block that is not moveable\n");
        printf("block pos: (%d, %d)", blok->row_pos, blok->col_pos);
        exit(-1);
    }

    switch (blok->typ) {
        case LINE:
            return move_line_block_down(board, (line_block *)blok);
        default:
            printf("not a type of block that we can place\n");
            exit(-1);
    }
    return NULL;
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
        for (int col = 0; col < COLS; col++) {
            printf("%c|", (*(gb->board + row) + col)->typ);
        }
        printf("\n");
    }
    printf("\n");

}

