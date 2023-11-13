#ifndef LINALG_MATVEC_H
#define LINALG_MATVEC_H

#include "vector.h"
#include "matrix.h"

vec mat_vec_mult(mat const A, vec const b, int const m, int const n);

void mat_permute(mat a, ivec const p);

#endif // LINALG_MATVEC_H