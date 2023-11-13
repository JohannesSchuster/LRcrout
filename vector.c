#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

vec alloc(int const n)
{
    return (vec)malloc(n*sizeof(double));
}

vec zero(int const n)
{
    return (vec)calloc(n, sizeof(double));
}

vec unit(int const d, int const n)
{
    vec res = zero(n);
    res[d] = 1;
    return res;
}

vec one(int const n)
{
    vec res = alloc(n);
    memset(res, (double)1, n*sizeof(double));
    return res;
}

vec copy(vec const a, int const n)
{
    vec res = alloc(n);
    memcpy(res, a, n*sizeof(double));
}

void scaleInp(vec a, double const s, int const n)
{
    for (int i=0; i<n; ++i) a[i] *= s;
}

void addInp(vec a, vec const b, int const n)
{
    for (int i=0; i<n; ++i) a[i] += b[i];
}

void subInp(vec a, vec const b, int const n)
{
    for (int i=0; i<n; ++i) a[i] -= b[i];
}

vec scale(vec const a, double const s, int const n)
{
    vec res = copy(a, n);
    scaleInp(res, s, n);
    return res;
}

vec add(vec const a, vec const b, int const n)
{
    vec res = copy(a, n);
    addInp(res, b, n);
    return res;
}

vec sub(vec const a, vec const b, int const n)
{
    vec res = copy(a, n);
    subInp(res, b, n);
    return res;
}

double scalarProd(vec const a, vec const b, int const n)
{
    double prod = 0;
    for (int i=0; i<n; ++i) 
        prod += a[i] * b[i];
    return prod;
}

double sqrNorm (vec const a, int const n)
{
    return scalarProd(a, a, n);
}

double norm(vec const a, int const n)
{
    return sqrt(sqrNorm(a, n));
}

double sqrDist(vec const a, vec const b, int const n)
{
    vec d = sub(b, a, n);
    return sqrNorm(d, n);
}

double dist(vec const a, vec const b, int const n)
{
    return sqrt(sqrDist(a, b, n));
}