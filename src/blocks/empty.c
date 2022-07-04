#include "../../include/block.h"
#include "../../include/empty.h"
#include "../../include/game_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

bool swap_empty_block(game_board *board, empty_block *e) {
    return false;
}

bool place_empty_block(game_board *board, empty_block *e, int row, int col) {

    /* Make an empty block and write it to game_board */
    if (e == NULL) {
        printf("Could not create the game_board\n");
        exit(-1);
    }
    *(*(board->board + row) + col) = *e;
    free(e);
    return true;
}

empty_block *make_empty_block() {
    empty_block *out = (empty_block *)malloc(sizeof(block));
    out->typ = EMPTY;
    out->dir = 0;
    out->dim = make_dimensions(1, 1);
    out->row_pos = 0;
    out->col_pos = 0;
    return out;
}
