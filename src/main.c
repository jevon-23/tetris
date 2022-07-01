#include "../include/game_board.h"
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
  print_game_board(board);
  printf("Successful build!\n");
  return 0;
}
