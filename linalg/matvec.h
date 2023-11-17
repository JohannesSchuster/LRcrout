#ifndef LINALG_MATVEC_H
#define LINALG_MATVEC_H

#include "defines.h"
#include "vector.h"
#include "matrix.h"

mat mat_diag(vec const d, size const m, size const n);
vec mat_vec_mult(mat const A, vec const b, size const m, size const n);

void mat_permute_linesInp(mat a, ivec const p, size const m, size const n);
void mat_permute_colsInp(mat a, ivec const p, size const m, size const n);

mat mat_permute_lines(mat const a, ivec const p, size const m, size const n);
mat mat_permute_cols(mat const a, ivec const p, size const m, size const n);

#endif // LINALG_MATVEC_H