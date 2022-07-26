#include "../../include/line.h"
#include "../../include/game_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

block *move_line_block(game_board *board, line_block *l, int row, int col);
void rotate_line_block(game_board *board, line_block *blok, bool direct);
bool place_line_block(game_board *board, line_block *l, int row, int col);

line_block *make_line_block() {
    line_block *out = (line_block *)malloc(sizeof(line_block));
    out->typ = LINE;
    out->dir = 0;
    out->dim = make_dimensions(4, 1);
    out->row_pos = 0;
    out->col_pos = ROWS / 2;

    /* Functions */
    out->move_block = move_line_block;
    out->rotate_block = rotate_line_block;
    out->place_block = place_line_block;
    return out;
}

/* Rotates the block in play, and places it on to the board */
void rotate_line_block(game_board *board, line_block *blok, bool direct) {

    (*blok).dir += 1;
    /* Even number => vertical block */
    if  (blok->dir % 2 == 0) {
        /* Check for collision */
        for (int i = 1; i < 4; i++) {
            block *b = get_block(board, blok->row_pos + i, blok->col_pos);
            if (b == NULL) continue;
            if (b->typ != EMPTY){
              (*blok).dir -=1;
              return;
            } 
        }
        (*blok).dim = make_dimensions(4, 1);
    }
    else {
        for (int i = 1; i < 4; i++) {
            block *b = get_block(board, blok->row_pos, blok->col_pos + i);
            if (b == NULL) continue;
            if (b->typ != EMPTY){
              (*blok).dir -=1;
              return;
            } 
        }
        (*blok).dim = make_dimensions(1, 4);
    }
    
    if (direct) {
      /* Free the old group of blocks */
      free_group(board, blok);

      /* Place the updated block based on position */
      place_block(board, blok, blok->row_pos, blok->col_pos);

    }
}


/* Move a line block down. First creates a new block and updates its fields,
 * then removes the og block from the game board, and prints the new block
 * to the board
 */
block *move_line_block(game_board *board, line_block *l, int row, int col) {
    if (row > l->row_pos) {

      /* Check for collision below */
      for (int i = 0; i < l->dim.cols; i++) {
        block *lower_block = get_block(board, l->row_pos+l->dim.rows, l->col_pos+i);
        if (lower_block == NULL) continue;
        if (lower_block->typ != EMPTY) {
            return NULL;
        }
      }
    }

    /* Check for collision on sides */
    if (col < l->col_pos) {
     for (int i = 0; i < l->dim.rows; i++) {
       block *lower_block = get_block(board, row+i, col);
       if (lower_block == NULL) continue;
       if (lower_block->typ != EMPTY) {
           return NULL;
       }

     }
    }
    
    /* Create a new line block, that is set 1 unit below current one */
    line_block *new_block = make_line_block(LINE);

    int new_row = row;
    int new_col = col;
    /* if we are @ a boundary, adjust */
    if (col < 0) new_col = 0;
    else if (col + l->dim.cols >= COLS) {
        new_col = COLS - l->dim.cols;
    }

    for (; new_block->dir != l->dir % 2; rotate_line_block(board, new_block, false));

    printf("wtf\n");
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
   
    /* Place the block */
    if  (l->dir % 4 == 0 || l->dir % 4 == 2) {
        for(int i = 0; i < 4; i++) {
            block *b = get_block(board, row + i, col);
            if (b->typ != EMPTY) return false; 
        }

        place_vertical_line_block(board, l, row, col);
    }
    else {
        for(int i = 0; i < 4; i++) {
            block *b = get_block(board, row, col + i);
            if (b->typ != EMPTY) return false; 
        }
        place_horizontal_line_block(board, l, row, col);
    }

    return true;
}




