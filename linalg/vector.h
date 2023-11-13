#ifndef LINALG_VECTOR_H
#define LINALG_VECTOR_H

typedef double* vec;
typedef int* ivec;

vec vec_zero(int const n);
vec vec_unit(int const d, int const n);
vec vec_one(int const n);

vec vec_copy(vec const a, int const n);

void vec_scaleInp(vec a, double const s, int const n);
void vec_addInp(vec a, vec const b, int const n);
void vec_subInp(vec a, vec const b, int const n);

vec vec_scale(vec const a, double const s, int const n);
vec vec_add(vec const a, vec const b, int const n);
vec vec_sub(vec const a, vec const b, int const n);

double vec_scalarProd(vec const a, vec const b, int const n);
double vec_sqrNorm (vec const a, int const n);
double vec_norm(vec const a, int const n);

double vec_sqrDist(vec const a, vec const b, int const n);
double vec_dist(vec const a, vec const b, int const n);

#endif // LINALG_VECTOR_H