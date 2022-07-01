#ifndef  BLOCK_H 
#define  BLOCK_H 

/* Repr blocks w/ color */
#define SQUARE 'Y' /* yellow */
#define HAT    'P' /* purple */
#define Z_LEFT 'R' /* red */
#define Z_RIGHT 'G' /* green */
#define LINE 'B' /* blue */
#define L_RIGHT 'C' /* cyan */
#define R_RIGHT 'O' /* orange */
#define EMPTY '_' /* grey */

/* Dimensions of a given block 
 * (can also be used for gameboard)
 */
typedef struct dimensions {
   int rows;
   int cols;
} dimensions;

/* Block struct */
/* My first attempt at inheritance in c!
 * Using the block struct as the common struct 
 * amongst all other different types of blocks.
 * On my end, I will just be using the block struct,
 * but under the hood it will be calling functions based
 * on TYP that is defined at the start. 
 *
 */
typedef struct block {
   char typ; /* Type of block we are dealing with */
   int dir; /* 0-3 */ 
   dimensions dim; /* Dimensions of this block */
   int row_pos;  /* The row position that this block is @ while falling */
   int col_pos;
} block;

/* Save rows and cols into one struct for easier packaging */
dimensions make_dimensions(int rows, int cols);
/* Make a block of the given TYP (square, line, hat, etc.) */
block *make_block(char typ);

/* Generate a random block */
block *generate_random_block();

#endif
