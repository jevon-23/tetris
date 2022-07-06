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

/* Rotates the block in play, and places it on to the board */
void rotate_line_block(game_board *board, line_block *blok, bool direct) {
    (*blok).dir += 1;
    /* Even number => vertical block */
    if  (blok->dir % 2 == 0) {
        (*blok).dim = make_dimensions(4, 1);
    }
    else {
        (*blok).dim = make_dimensions(1, 4);
    }
    /* Free the old group of blocks */
    free_group(board, blok);
    
    if (direct)
      /* Place the updated block based on position */
      place_block(board, blok, blok->row_pos, blok->col_pos);
}


/* Move a line block down. First creates a new block and updates its fields,
 * then removes the og block from the game board, and prints the new block
 * to the board
 */
block *move_line_block(game_board *board, line_block *l, int row, int col) {
    /* Check for collision */
    for (int i = 0; i < l->dim.cols; i++) {
      block *lower_block = get_block(board, l->row_pos+l->dim.rows, l->col_pos+i);
      if (lower_block == NULL) continue;
      if (lower_block->typ != EMPTY) {
          return NULL;
      }
    }
    
    /* Create a new line block, that is set 1 unit below current one */
    line_block *new_block = make_line_block(LINE);

    int new_row = row;
    int new_col = col;
    if (col < 0) new_col = 0;
    else if (col + l->dim.cols >= COLS) {
        /* if we are @ a boundary, set us up right */
        new_col = COLS - l->dim.cols;
    }

    for (; new_block->dir != l->dir % 2; rotate_line_block(board, new_block, false));

    /* Free previous block group */
    free_block_group(board, (block *)l);

    /* place the new block  */
    place_block(board,new_block, new_row, new_col);

    return new_block;
}



/* Places a vertical line block on the board */
bool place_vertical_line_block(game_board *board, line_block *l, int row, int col) {
    for (int i = 0; i < l->dim.rows; i++) {
        /* Place the value on the board */
        *(*(board->board + i + row) + col) = *l;
        
        /* Update the group to have the right blocks */
        l->group[i].rows = i + row;
        l->group[i].cols = col;
    }
    return true;
}

/* Places a horizontal line block on the board */
bool place_horizontal_line_block(game_board *board, line_block *l, int row, int col) {
    printf("l->dim = (%d, %d)\n", l->dim.rows, l->dim.cols);
    if (l->dim.cols + col >= COLS) {
        col = COLS - 4;
        printf("hello ww\n");
    }
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
    /* Check to see if we are placing a block out of bounds */
    if (col + l->dim.cols > COLS)
        col = COLS - l->dim.cols;
    if (col < 0 ) col = 0;
    if (row < 0) row = 0;
    if (row + l->dim.rows > ROWS)
        row = ROWS - l->dim.rows;
   
    printf("place->dir = %d\n", l->dir);
    /* Place the block */
    if  (l->dir % 4 == 0 || l->dir % 4 == 2)
        place_vertical_line_block(board, l, row, col);
    else {
        place_horizontal_line_block(board, l, row, col);
    }

    return true;
}




