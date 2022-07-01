#include "../../include/empty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

block *make_block(char typ) {
    switch (typ) {
        case EMPTY:
            empty_block *e = make_empty_block();
            return (block *)e;

        default:
            printf("invalid block type\n");
    }
    return NULL;
}

dimensions make_dimensions(int rows, int cols) {
    dimensions out;
    out.rows = rows;
    out.cols = cols;
    return out;
}
