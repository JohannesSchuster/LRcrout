#include "matrix.h"
#include "utils.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

mat mat_alloc(size const m, size const n)
{
    return (mat)malloc(m*n*sizeof(value));
}

mat mat_zero(size const m, size const n)
{
    return (mat)calloc(m*n, sizeof(value));
}

mat mat_identity(size const m, size const n)
{
    mat res = mat_zero(m, n);
    for (idx i = 0; i<smin(m,n); ++i) res[i*m+i] = 1;
    return res;
}

mat mat_copy(mat const a, size const m, size const n)
{
    mat res = mat_alloc(m, n);
    memcpy(res, a, m*n*sizeof(value));
}

void mat_scaleInp(mat a, value const s, size const m, size const n)
{
    for (idx i=0; i<m*n; ++i) a[i] *= s;
}

void mat_addInp(mat a, mat const b, size const m, size const n)
{
    for (idx i=0; i<m*n; ++i) a[i] += b[i];
}

void mat_subInp(mat a, mat const b, size const m, size const n)
{
    for (idx i=0; i<m*n; ++i) a[i] -= b[i];
}

void mat_swap_lineInp(mat a, size const m, size const n, idx const i, idx const j)
{
    for (idx k=0; k<n; ++k)
    {
        value buff = a[i*n+k];
        a[i*n+k] = a[j*n+k];
        a[j*n+k] = buff;
    }
}

void mat_swap_colInp(mat a, size const m, size const n, idx const i, idx const j)
{
    for (idx k=0; k<m; ++k)
    {
        value buff = a[k*n+i];
        a[k*n+i] = a[k*n+j];
        a[k*n+j] = buff;
    }
}

mat mat_scale(mat const a, value const s, size const m, size const n)
{
    mat res = mat_copy(a, m, n);
    mat_scaleInp(res, s, m, n);
    return res;
}

mat mat_add(mat const a, mat const b, size const m, size const n)
{
    mat res = mat_copy(a, m, n);
    mat_addInp(res, b, m, n);
    return res;
}

mat mat_sub(mat const a, mat const b, size const m, size const n)
{
    mat res = mat_copy(a, m, n);
    mat_subInp(res, b, m, n);
    return res;
}

mat mat_mult(mat const a, mat const b, size const l, size const m, size const n)
{
    mat res = mat_alloc(l, n);
    for (idx i=0; i<l; ++i)
    {
        for (idx k=0; k<n; ++k)
        {
            res[i*n+k] = 0;
            for (idx j=0; j<m; ++j)
            {
                res[i*n+k] += a[i*m+j] * b[j*n+k];
            }
        }
    }
    return res;
}

mat mat_trans(mat const a, size const m, size const n)
{
    mat trans = mat_alloc(n,m);
    for (idx i=0; i<m; ++i)
    {
        for (idx j=0; j<n; ++j)
        {
            trans[j*m+i] = a[i*n+j];
        }
    }
    return trans;
}

mat mat_swap_line(mat const a, size const m, size const n, idx const i, idx const j)
{
    mat ret = mat_copy(a, m, n);
    mat_swap_lineInp(ret, m, n, i, j);
    return ret;
}

mat mat_swap_col(mat const a, size const m, size const n, idx const i, idx const j)
{
    mat ret = mat_copy(a, m, n);
    mat_swap_colInp(ret, m, n, i, j);
    return ret;
}
