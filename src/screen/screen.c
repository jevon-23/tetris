#include "../../include/screen.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

/* Throws an sdl error and exits the program */
void throw_sdl_err() {
    printf("sdl2 err: %s\n", SDL_GetError());
    exit(-1);
}

/* Update the screen based on the events that were passed in */
void update(screen *s) {
  /* While user did not try to exit program */
  bool open = true;
  while (open) {

    /* Poll events, and execute functionality based on inputs */
    while (SDL_PollEvent(&s->event) > 0) {
        switch (s->event.type) {
            /* quit */
            case SDL_QUIT:
                open = false;
                break;
            default:
                printf("don't know what the event is \n");
        }
    }
  }
}


/* Make a block of whatever TYP is passed in. Calls 
 * the internal function associated with TYP.
 */
void change_color(screen *s, char typ) {
    switch (typ) {
        case EMPTY:
            SDL_SetRenderDrawColor(s->renderer, 40, 40, 40, 255);
            break;
        case LINE:
            SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 255);
            break;

        default:
            printf("invalid block type\n");
    }
}
coords map_coords(int x, int y) {
    coords out;
    out.rows = (int) ((float)WINDOW_WIDTH / (float) 5) + ((BLOCK_WIDTH + 2)* x);
    out.cols = (int) ((float)WINDOW_HEIGHT / (float) 5) + ((BLOCK_HEIGHT+2) * y);
    return out;
}

/* Render the gameboard */
void draw_board(screen *s, game_board *board) {
    print_game_board(board);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            coords pos = map_coords(i, j);
            SDL_Rect sq;
            sq.x = pos.cols + 140;
            sq.y = pos.rows - 75;
            sq.w = 15;
            sq.h = 15;

            change_color(s, (*(board->board + i) + j)->typ);
            SDL_RenderFillRect(s->renderer, &sq);
        }
    } 
    SDL_RenderPresent(s->renderer);
}

/* Free */
void clean_up(screen *s) {
    SDL_DestroyWindow(s->window);
}

/* Initialize the screen */
screen *init_screen() {

    /* Initialize a sdl for video */
    if (SDL_Init(SDL_INIT_VIDEO ) < 0) {
        printf("screen initialization failed\n");
        exit(-1);
    }

    /* Create a new Window */
    SDL_Window *window = SDL_CreateWindow(
            "Tetris Window",
            SDL_WINDOWPOS_CENTERED,                                
            SDL_WINDOWPOS_CENTERED,
            WINDOW_HEIGHT, WINDOW_WIDTH,
            0
    );
    if (!window) {
        printf("window was not created\n");
        throw_sdl_err();
    }


    /* Create a renderer */
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("renderer not created\n");
        throw_sdl_err();
    }

    /* Create the screen object that we want to return */
    screen *new_screen = (screen *)malloc(sizeof(screen));
    new_screen->window = window;
    new_screen->renderer = renderer;
    return new_screen;
}
