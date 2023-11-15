#include "matrix.h"
#include "utils.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

mat mat_alloc(int const m, int const n)
{
    return (mat)malloc(m*n*sizeof(double));
}

mat mat_zero(int const m, int const n)
{
    return (mat)calloc(m*n, sizeof(double));
}

mat mat_identity(int const m, int const n)
{
    mat res = mat_zero(m, n);
    for (int i = 0; i<imin(m,n); ++i) res[i*m+i] = 1;
    return res;
}

mat mat_copy(mat const a, int const m, int const n)
{
    mat res = mat_alloc(m, n);
    memcpy(res, a, m*n*sizeof(double));
}

void mat_scaleInp(mat a, double const s, int const m, int const n)
{
    for (int i=0; i<m*n; ++i) a[i] *= s;
}

void mat_addInp(mat a, mat const b, int const m, int const n)
{
    for (int i=0; i<m*n; ++i) a[i] += b[i];
}

void mat_subInp(mat a, mat const b, int const m, int const n)
{
    for (int i=0; i<m*n; ++i) a[i] -= b[i];
}

mat mat_scale(mat const a, double const s, int const m, int const n)
{
    mat res = mat_copy(a, m, n);
    mat_scaleInp(res, s, m, n);
    return res;
}

mat mat_add(mat const a, mat const b, int const m, int const n)
{
    mat res = mat_copy(a, m, n);
    mat_addInp(res, b, m, n);
    return res;
}

mat mat_sub(mat const a, mat const b, int const m, int const n)
{
    mat res = mat_copy(a, m, n);
    mat_subInp(res, b, m, n);
    return res;
}

mat mat_mult(mat const a, mat const b, int const l, int const m, int const n)
{
    mat res = mat_alloc(l, n);
    for (int i=0; i<l; ++i)
    {
        for (int k=0; k<n; ++k)
        {
            res[i*n+k] = 0;
            for (int j=0; j<m; ++j)
            {
                res[i*n+k] += a[i*m+j] * b[j*n+k];
            }
        }
    }
    return res;
}