#ifndef LINALG_MATVEC_H
#define LINALG_MATVEC_H

#include "vector.h"
#include "matrix.h"

vec mat_vec_mult(mat const A, vec const b, int const m, int const n);

void mat_permute_lines(mat a, ivec const p, int const m, int const n);
void mat_permute_cols(mat a, ivec const p, int const m, int const n);


#endif // LINALG_MATVEC_H