#include "../../include/line.h"
#include "../../include/game_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

line_block *make_line_block() {
    line_block *out = (line_block *)malloc(sizeof(line_block));
    out->typ = LINE;
    out->dir = 0;
    out->dim = make_dimensions(4, 1);
    out->row_pos = 0;
    out->col_pos = ROWS / 2;
    return out;
}

void rotate_line_block(game_board *board, line_block *blok) {
    (*blok).dir += 1;
    /* Even number => vertical block */
    if  (blok->dir % 2 == 0) {
        (*blok).dim = make_dimensions(4, 1);
    }
    else {
        (*blok).dim = make_dimensions(1, 4);
    }
    free_group(board, blok);
    place_block(board, blok, blok->row_pos, blok->col_pos);
}

block *move_vertical_line_block_down(game_board *board, line_block *l) {

    /* Check to see if we can actually move this block down */
    if (l->row_pos + 1 >= ROWS) {
        return NULL;
    }

    /* Check for collision */
    block *lower_block = get_block(board, l->row_pos+l->dim.rows, l->col_pos);
    if (lower_block == NULL || lower_block->typ != EMPTY)
        return NULL;
    
    /* Create a new line block, that is set 1 unit below current one */
    line_block *new_block = make_line_block(LINE);

    int new_row = l->row_pos + 1;
    int new_col = l->col_pos;

    /* Free previous block group */
    free_block_group(board, (block *)l);

    /* place the new block  */
    place_block(board,new_block, new_row, new_col);

    return new_block;
}

block *move_horizontal_line_block_down(game_board *board, line_block *l) {
    /* Check to see if we can actually move this block down */
    if (l->row_pos + 1 >= ROWS) {
        return NULL;
    }

    /* Check for collision */
    block *lower_block = get_block(board, l->row_pos+l->dim.rows, l->col_pos);
    if (lower_block == NULL || lower_block->typ != EMPTY) {
        printf("row pos = %d ~ dim_rows = %d, col_pos = %d, dim_cols = %d\n", l->row_pos, l->dim.rows, l->col_pos, l->dim.cols);

    }
    
    /* Create a new line block, that is set 1 unit below current one */
    line_block *new_block = make_line_block(LINE);

    int new_row = l->row_pos + 1;
    int new_col = l->col_pos;

    for (; new_block->dir != l->dir % 2; rotate_line_block(board, new_block));

    /* Free previous block group */
    free_block_group(board, (block *)l);

    /* place the new block  */
    place_block(board,new_block, new_row, new_col);

    return new_block;
}

block *move_line_block_down(game_board *board, line_block *l) {
    if (l->dir % 4 == 0 || l->dir % 4 == 2)
        return move_vertical_line_block_down(board, l);
    else
        return move_horizontal_line_block_down(board, l);
    return NULL;
}


bool place_vertical_line_block(game_board *board, line_block *l, int row, int col) {
    /* Check to see if we are placinga block out of bounds */
    if ((row + l->dim.rows > ROWS || row < 0 ) || (col + l->dim.cols > COLS || col < 0)) {
        return false;
    }

    /* Place the block on the board, save the group coords to the block */
    for (int i = 0; i < l->dim.rows; i++) {
        /* Place the value on the board */
        *(*(board->board + i + row) + col) = *l;
        
        /* Update the group to have the right blocks */
        l->group[i].rows = i + row;
        l->group[i].cols = col;
    }
    return true;
}

bool place_horizontal_line_block(game_board *board, line_block *l, int row, int col) {
    /* Check to see if we are placinga block out of bounds */
    if ((row + l->dim.rows > ROWS || row < 0 ) || (col + l->dim.cols > COLS || col < 0)) {
        return false;
    }

    /* Place the block on the board, save the group coords to the block */
    for (int i = 0; i < l->dim.cols; i++) {
        /* Place the value on the board */
        *(*(board->board + row) + col + i) = *l;
        
        /* Update the group to have the right blocks */
        l->group[i].rows = row;
        l->group[i].cols = col + i;
    }
    return true;

}

bool place_line_block(game_board *board, line_block *l, int row, int col) {
    if  (l->dir % 4 == 0 || l->dir % 4 == 2)
        place_vertical_line_block(board, l, row, col);
    else {
        place_horizontal_line_block(board, l, row, col);
    }

    return true;
}




