#include "../include/game_board.h"
#include "../include/line.h"
#include <float.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  
 * Set up a little set up screen where we ask the user if they want
 * to play or if they watch the ai play, whenever we make that
 */
int processCLI(int argc, char **argv, char **filename) {
  if (argc != 2) {
    printf("usage:");
    exit(-1);
  }
  return 0;
}

int main(int arg, char *argv[]) {
  /* Generate this games' board */
  game_board *board = make_game_board();
  printf("made the game_board\n");
  block *l = make_block(LINE);

  place_block(board, l, 0, COLS/2);
  print_game_board(board);

  block *next = move_block_down(board, (block *)l);
  print_game_board(board);

  next = move_block_right(board, next);
  print_game_board(board);

  next = move_block_right(board, next);
  print_game_board(board);

  while (next != NULL) {
    rotate_block(board, next);
    next = move_block_down(board, next);
    print_game_board(board);
  }
  printf("Successful build!\n");
  return 0;
}
