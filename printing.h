#ifndef PRINTING_H
#define PRINTING_H

#include "linalg/defines.h"
#include "linalg/vector.h"
#include "linalg/matrix.h"

void vec_print(vec const a, size const n);
void ivec_print(ivec const a, size const n);
void mat_print(mat const a, size const m, size const n);

#endif