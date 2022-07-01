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

void rotate_line_block(line_block *blok) {
    (*blok).dir += 1;
    if  (blok->dir % 4 == 0 || blok->dir % 4 == 2)
        (*blok).dim = make_dimensions(4, 1);
    else
        (*blok).dim = make_dimensions(1, 4);
}

void draw_vertical_line_block(game_board *board, line_block *blok);
void draw_horizontal_line_block(game_board *board, line_block *blok);

// FIXME
void draw_vertical_line_block(game_board *board, line_block *blok) {
}

// FIXME
void draw_horizontal_line_block(game_board *board, line_block *blok) {
}

/* 
 * Draws a block to the game_board based on its direction to determine
 * how to draw 
 */
void draw_line_block(game_board *board, line_block *blok) {
    if  (blok->dir % 4 == 0 || blok->dir % 4 == 2)
        draw_vertical_line_block(board, blok);
    else
        draw_horizontal_line_block(board, blok);
}


