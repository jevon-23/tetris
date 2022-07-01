#ifndef  BLOCK_H 
#define  BLOCK_H 

/* Repr blocks w/ color */
#define SQUARE 'Y' /* yellow */
#define HAT  'P' /* purple */
#define Z_LEFT 'R' /* red */
#define Z_RIGHT 'G' /* green */
#define LINE 'B' /* blue */
#define L_RIGHT 'C' /* cyan */
#define R_RIGHT 'O' /* orange */
#define EMPTY '_' /* grey */

typedef struct dimensions {
   int rows;
   int cols;
} dimensions;

typedef struct block {
   char typ;
   int dir; /* 0-3 */ 
   dimensions dim;
} block;

dimensions make_dimensions(int rows, int cols);
block *make_block(char typ);
block *generate_random_block();

#endif
