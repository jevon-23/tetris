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
  block *next = make_block(SQUARE);
  block *prev = malloc(sizeof(block));
  *prev = *next;

  place_block(board, next, 0, COLS / 2);
  print_game_board(board);
  place_block(board, next, 0, COLS / 2);
  print_game_board(board);

  //  for (int i = 0; i < 12; i++) {
  //  while (next != NULL) {
  //    next = move_block_down(board, (block *)next);
  //    print_game_board(board);
  //    if (next == NULL) break;
  //    *prev = *next;
  //
  //    next = move_block_left(board, next);
  //    print_game_board(board);
  //    if (next == NULL){
  //      next = malloc(sizeof(block));
  //      *next = *prev;
  //    }
  //    *prev = *next;
  //
  //    next = move_block_right(board, next);
  //    print_game_board(board);
  //    if (next == NULL){
  //      *next = *prev;
  //    }
  //    *prev = *next;
  //
  //    rotate_block(board, next);
  //    print_game_board(board);
  //  }
  //  prev->active = false;
  //
  //  next = make_block(LINE);
  //  if (place_block(board, next, 0, COLS/2) == false)
  //      break;
  //  if (i % 2 == 0){
  //
  //    next = move_block_right(board, next);
  //    next = move_block_right(board, next);
  //  }
  //  if (i % 3 == 0) {
  //    next = move_block_left(board, next);
  //    next = move_block_left(board, next);
  //    next = move_block_left(board, next);
  //  }
  //  if (i % 4 == 0) {
  //    next = move_block_left(board, next);
  //    next = move_block_left(board, next);
  //  }
  //  if (i % 5 == 0) {
  //    next = move_block_right(board, next);
  //    next = move_block_right(board, next);
  //  }
  //    print_game_board(board);
  //}

  printf("Successful build!\n");
  return 0;
}
