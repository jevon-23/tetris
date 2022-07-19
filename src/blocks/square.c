#include "../../include/square.h"
#include "../../include/game_board.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Checks for collisions in direction that we are trying to move in */
bool collision(game_board *board, square_block *s, int dir, int row, int col);

/* Does not rotate in any way b/c it is a square */
void rotate_square_block(game_board *board, square_block *s, bool direct) {
  return;
}

square_block *make_square() {
  square_block *out = (square_block *)malloc(sizeof(square_block));
  out->typ = SQUARE;
  out->dir = 0;
  out->dim = make_dimensions(2, 2); /* 2 x 2 */
  out->row_pos = 0;
  out->col_pos = ROWS / 2;

  /* Functions */
  out->move_block = move_square;
  out->rotate_block = rotate_square_block;
  out->place_block = place_square;
  return out;
}

block *move_square(game_board *board, square_block *s, int row, int col) {
  return NULL;
}

/* dir == what way are we moving */
bool square_collision(game_board *board, square_block *s, int dir, int row,
                      int col) {

  switch (dir) {

  case 0:
    for (int i = 0; i < s->dim.rows; i++) {
      block *b = get_block(board, row + i, col);
      block *bl = get_block(board, row + i, col + 1);
      if (b->typ != EMPTY || bl->typ != EMPTY)
        return true;
    }
    break;

  default:
    printf("invalid collision direction: %d\n", dir);
    exit(-1);
  }
  return false;
}

bool place_square(game_board *board, square_block *s, int row, int col) {

  /* Create a new square block, that is set 1 unit below current one */
  square_block *new_block = make_square();

  /* Check to see if we are placing a block out of bounds */
  if (col + s->dim.cols > COLS)
    col = COLS - s->dim.cols;
  if (col < 0)
    col = 0;
  if (row < 0)
    row = 0;

  if (square_collision(board, s, 0, row, col))
    return false;
  for (int i = 0; i < s->dim.rows; i++) {
    /* Place the value on the board */
    *(*(board->board + i + row) + col) = *s;
    *(*(board->board + i + row) + col - 1) = *s;

    /* Update the group to have the right blocks */
    s->group[i].rows = i + row;
    s->group[i].cols = col;
  }

  return new_block;
}
