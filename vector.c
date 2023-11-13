#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

vec vec_alloc(int const n)
{
    return (vec)malloc(n*sizeof(double));
}

vec vec_zero(int const n)
{
    return (vec)calloc(n, sizeof(double));
}

vec vec_unit(int const d, int const n)
{
    vec res = vec_zero(n);
    res[d] = 1;
    return res;
}

vec vec_one(int const n)
{
    vec res = vec_alloc(n);
    memset(res, (double)1, n*sizeof(double));
    return res;
}

vec vec_copy(vec const a, int const n)
{
    vec res = vec_alloc(n);
    memcpy(res, a, n*sizeof(double));
}

void vec_scaleInp(vec a, double const s, int const n)
{
    for (int i=0; i<n; ++i) a[i] *= s;
}

void vec_addInp(vec a, vec const b, int const n)
{
    for (int i=0; i<n; ++i) a[i] += b[i];
}

void vec_subInp(vec a, vec const b, int const n)
{
    for (int i=0; i<n; ++i) a[i] -= b[i];
}

vec vec_scale(vec const a, double const s, int const n)
{
    vec res = vec_copy(a, n);
    vec_scaleInp(res, s, n);
    return res;
}

vec vec_add(vec const a, vec const b, int const n)
{
    vec res = vec_copy(a, n);
    vec_addInp(res, b, n);
    return res;
}

vec vec_sub(vec const a, vec const b, int const n)
{
    vec res = vec_copy(a, n);
    vec_subInp(res, b, n);
    return res;
}

double vec_scalarProd(vec const a, vec const b, int const n)
{
    double prod = 0;
    for (int i=0; i<n; ++i) 
        prod += a[i] * b[i];
    return prod;
}

double vec_sqrNorm (vec const a, int const n)
{
    return vec_scalarProd(a, a, n);
}

double vec_norm(vec const a, int const n)
{
    return sqrt(vec_sqrNorm(a, n));
}

double vec_sqrDist(vec const a, vec const b, int const n)
{
    vec d = vec_sub(b, a, n);
    return vec_sqrNorm(d, n);
}

double vec_dist(vec const a, vec const b, int const n)
{
    return sqrt(vec_sqrDist(a, b, n));
}