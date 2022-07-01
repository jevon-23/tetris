#include "../../include/empty.h"
#include "../../include/game_board.h"
#include "../../include/block.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

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
            if (e == NULL) {
                printf("Could not create the game_board\n");
                exit(-1);
            }
           *(*(gb->board + i) + j) = *e;
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

}

