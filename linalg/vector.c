#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

vec vec_alloc(size const n)
{
    return (vec)malloc(n*sizeof(value));
}

vec vec_zero(size const n)
{
    return (vec)calloc(n, sizeof(value));
}

vec vec_unit(size const d, size const n)
{
    vec res = vec_zero(n);
    res[d] = 1;
    return res;
}

vec vec_one(size const n)
{
    vec res = vec_alloc(n);
    memset(res, (value)1, n*sizeof(value));
    return res;
}

vec vec_copy(vec const a, size const n)
{
    vec res = vec_alloc(n);
    memcpy(res, a, n*sizeof(value));
}

void vec_scaleInp(vec a, value const s, size const n)
{
    for (idx i=0; i<n; ++i) a[i] *= s;
}

void vec_addInp(vec a, vec const b, size const n)
{
    for (idx i=0; i<n; ++i) a[i] += b[i];
}

void vec_subInp(vec a, vec const b, size const n)
{
    for (idx i=0; i<n; ++i) a[i] -= b[i];
}

vec vec_scale(vec const a, value const s, size const n)
{
    vec res = vec_copy(a, n);
    vec_scaleInp(res, s, n);
    return res;
}

vec vec_add(vec const a, vec const b, size const n)
{
    vec res = vec_copy(a, n);
    vec_addInp(res, b, n);
    return res;
}

vec vec_sub(vec const a, vec const b, size const n)
{
    vec res = vec_copy(a, n);
    vec_subInp(res, b, n);
    return res;
}

value vec_scalarProd(vec const a, vec const b, size const n)
{
    value prod = 0;
    for (idx i=0; i<n; ++i) 
        prod += a[i] * b[i];
    return prod;
}

value vec_sqrNorm (vec const a, size const n)
{
    return vec_scalarProd(a, a, n);
}

value vec_norm(vec const a, size const n)
{
    return sqrt(vec_sqrNorm(a, n));
}

value vec_sqrDist(vec const a, vec const b, size const n)
{
    vec d = vec_sub(b, a, n);
    return vec_sqrNorm(d, n);
}

value vec_dist(vec const a, vec const b, size const n)
{
    return sqrt(vec_sqrDist(a, b, n));
}