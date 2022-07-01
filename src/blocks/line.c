#include "../../include/line.h"
#include "../../include/game_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

void place_vertical_line_block(game_board *board, line_block *l, int row, int col);
void place_horizontal_line_block(game_board *board, line_block *l, int row, int col);

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

void place_vertical_line_block(game_board *board, line_block *l, int row, int col) {
    for (int i = 0; i < l->dim.rows; i++) {
        *(*(board->board + i + row) + col) = *l;
    }
}

void place_horizontal_line_block(game_board *board, line_block *l, int row, int col) {

}

bool place_line_block(game_board *board, line_block *l, int row, int col) {
    if  (l->dir % 4 == 0 || l->dir % 4 == 2)
        place_vertical_line_block(board, l, row, col);
    else {
        place_horizontal_line_block(board, l, row, col);
    }

    return true;
}




