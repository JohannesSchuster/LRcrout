#ifndef LINALG_MATRIX_H
#define LINALG_MATRIX_H

#include "defines.h"

mat mat_alloc_cols(size const m);
mat mat_alloc(size const m, size const n);
mat mat_zero(size const m, size const n);
mat mat_identity(size const m, size const n);
mat mat_copy(mat const a, size const m, size const n);

void mat_scaleInp(mat a, value const s, size const m, size const n);
void mat_addInp(mat a, mat const b, size const m, size const n);
void mat_subInp(mat a, mat const b, size const m, size const n);
void mat_swap_lineInp(mat a, size const m, size const n, idx const i, idx const j);
void mat_swap_colInp(mat a, size const m, size const n, idx const i, idx const j);

mat mat_scale(mat const a, value const s, size const m, size const n);
mat mat_add(mat const a, mat const b, size const m, size const n);
mat mat_sub(mat const a, mat const b, size const m, size const n);
mat mat_mult(mat const a, mat const b, size const l, size const m, size const n);

mat mat_trans(mat const a, size const m, size const n);
mat mat_swap_line(mat const a, size const m, size const n, idx const i, idx const j);
mat mat_swap_col(mat const a, size const m, size const n, idx const i, idx const j);

void mat_free(mat a, size const m);

#endif // LINALG_MATRIX_H