#include "game_board.h"
#include <SDL2/SDL.h>
#ifndef  SCREEN_H 
#define  SCREEN_H 

#define WINDOW_HEIGHT  680
#define WINDOW_WIDTH   480
#define BLOCK_HEIGHT   15
#define BLOCK_WIDTH    15


typedef struct screen {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
} screen;

screen *init_screen();
void clean_up(screen *s);
void update(screen *s);
void draw(screen *s);
void draw_board(screen *s, game_board *board);
#endif
