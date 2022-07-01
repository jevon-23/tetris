#include "../../include/block.h"
#include "../../include/empty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>

empty_block *make_empty_block() {
    empty_block *out = (empty_block *)malloc(sizeof(block));
    out->typ = EMPTY;
    out->dir = 0;
    out->dim = make_dimensions(1, 1);
    out->row_pos = 0;
    out->col_pos = 0;
    return out;
}
