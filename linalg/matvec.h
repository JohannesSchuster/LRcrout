#ifndef LINALG_MATVEC_H
#define LINALG_MATVEC_H

#include "defines.h"
#include "vector.h"
#include "ivector.h"
#include "matrix.h"

mat mat_diag(vec const d, size const m, size const n);
mat mat_from_vec(vec const a, size const m, size const n);
mat mat_copy_from_vec(vec const a, size const m, size const n);
vec mat_vec_mult(mat const A, vec const b, size const m, size const n);

void vec_permuteInp(vec a, ivec const p, size const n);
vec vec_permute(vec const a, ivec const p, size const n);

void ivec_permuteInp(ivec a, ivec const p, size const n);
ivec ivec_permute(ivec const a, ivec const p, size const n);

void ivec_invert_permutationInp(ivec a, size const n);
ivec ivec_invert_permutation(ivec const a, size const n);

void mat_permute_linesInp(mat a, ivec const p, size const m, size const n);
void mat_permute_colsInp(mat a, ivec const p, size const m, size const n);

mat mat_permute_lines(mat const a, ivec const p, size const m, size const n);
mat mat_permute_cols(mat const a, ivec const p, size const m, size const n);

#endif // LINALG_MATVEC_H