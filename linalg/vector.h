#ifndef LINALG_VECTOR_H
#define LINALG_VECTOR_H

#include "defines.h"

vec vec_alloc(size const n);
vec vec_zero(size const n);
vec vec_unit(size const d, size const n);
vec vec_one(size const n);

vec vec_copy(vec const a, size const n);

void vec_scaleInp(vec a, value const s, size const n);
void vec_addInp(vec a, vec const b, size const n);
void vec_subInp(vec a, vec const b, size const n);
void vec_swapInp(vec a, size const n, idx const i, idx const j);

vec vec_scale(vec const a, value const s, size const n);
vec vec_add(vec const a, vec const b, size const n);
vec vec_sub(vec const a, vec const b, size const n);
vec vec_swap(vec const a, size const n, idx const i, idx const j);

value vec_scalarProd(vec const a, vec const b, size const n);
value vec_sqrNorm (vec const a, size const n);
value vec_norm(vec const a, size const n);

value vec_sqrDist(vec const a, vec const b, size const n);
value vec_dist(vec const a, vec const b, size const n);




#endif // LINALG_VECTOR_H