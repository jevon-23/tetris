#include "../include/game_board.h"
#include "../include/line.h"
#include "../include/screen.h"
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
  block *next = make_block(LINE);
  block *prev = malloc(sizeof(block));
  *prev = *next;

  screen *s = init_screen();
  SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
  SDL_RenderClear(s->renderer);

  /* change render color */
  SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 255);
  SDL_UpdateWindowSurface(s->window);
  draw_board(s, board);

  place_block(board, next, 0, COLS/2);
  print_game_board(board);
  draw_board(s, board);
  SDL_Delay(1000);
  // next = move_block_down(board, (block *)next);
  // print_game_board(board);
  // draw_board(s, board);
  // SDL_Delay(1000);
  // next = move_block_left(board, next);
  // print_game_board(board);
  // draw_board(s, board);
  // SDL_Delay(1000);
  // next = move_block_right(board, next);
  // print_game_board(board);
  // draw_board(s, board);
  // SDL_Delay(1000);
  // rotate_block(board, next);
  // print_game_board(board);
  // draw_board(s, board);

  for (int i = 0;; i++) {
    while (next != NULL) {
        printf("guess it\n");
      next = move_block_down(board, (block *)next);
      printf("guess\n");
      print_game_board(board);
      draw_board(s, board);
      SDL_Delay(100);
      if (next == NULL) break;
      *prev = *next;

      next = move_block_left(board, next);
      print_game_board(board);
      draw_board(s, board);
      SDL_Delay(100);
      if (next == NULL){
        next = malloc(sizeof(block));
        *next = *prev;
      }
      *prev = *next;

      next = move_block_right(board, next);
      print_game_board(board);
      draw_board(s, board);
      SDL_Delay(100);
      if (next == NULL){
        *next = *prev;
      }
      *prev = *next;

      rotate_block(board, next);
      print_game_board(board);
      draw_board(s, board);
      SDL_Delay(100);
    }
  prev->active = false;

  next = make_block(LINE);
  if (place_block(board, next, 0, COLS/2) == false)
      break;
  if (i % 2 == 0){

    next = move_block_right(board, next);
    rotate_block(board, next);
    next = move_block_right(board, next);
  }
  if (i % 3 == 0) {
    next = move_block_left(board, next);
    next = move_block_left(board, next);
    rotate_block(board, next);
    next = move_block_left(board, next);
  }
  if (i % 4 == 0) {
    next = move_block_left(board, next);
    next = move_block_left(board, next);
  }
  if (i % 5 == 0) {
    next = move_block_right(board, next);
    next = move_block_right(board, next);
  }

  print_game_board(board);
  draw_board(s, board);
  }

  /* SDL_Delay(5000); */

  /* Poll for events */
  bool open = true;
  while (open) {

    SDL_Event e;
    while (SDL_PollEvent(&e) > 0) {
        switch (e.type) {
            /* quit */
            case SDL_KEYDOWN:
                /* The scancode of the key that was pushed down */
                uint16_t key_code = e.key.keysym.scancode;
                switch (key_code) {
                    case SDL_SCANCODE_ESCAPE:
                        open = false;
                        break;
                }
                break;
            case SDL_QUIT:
                open = false;
                break;
            default:

              /* Set render color to red & clear window */
              SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
              SDL_RenderClear(s->renderer);

              /* change render color */
              SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 255);

              /* draw_board(s, board); */

              /* Draw rectangle to screen */
              // SDL_RenderFillRect(s->renderer, &sq);
              // SDL_RenderFillRect(s->renderer, &sq2);

              // /* Render screen */
              // SDL_RenderPresent(s->renderer);

              printf("no event passed in\n");
        }
    }
  }

  printf("Successful build!\n");
  return 0;
}
