#ifndef LINALG_H
#define LINALG_H

#include "vector.h"
#include "matrix.h"
#include "blatt4.h"

vec mat_vec_mult(mat const A, vec const b, int const m, int const n);

#endif