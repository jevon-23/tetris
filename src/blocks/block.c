#include "../../include/empty.h"
#include "../../include/line.h"
#include "../../include/square.h"
#include <float.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Generates a block of a random type */
block *generate_random_block() {
  block *out = (block *)make_block(EMPTY);
  return out;
}

/* Make a block of whatever TYP is passed in. Calls
 * the internal function associated with TYP.
 */
block *make_block(char typ) {
  empty_block *e;
  line_block *l;
  square_block *s;
  switch (typ) {
  case EMPTY:
    e = make_empty_block();
    return (block *)e;
  case LINE:
    l = make_line_block();
    return (block *)l;
  case SQUARE:
    s = make_square();
    return (block *)s;

  default:
    printf("invalid block type\n");
  }
  return NULL;
}

/* Create the struct that holds the dimensions of this block */
dimensions make_dimensions(int rows, int cols) {
  dimensions out;
  out.rows = rows;
  out.cols = cols;
  return out;
}
