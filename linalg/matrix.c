#include "matrix.h"
#include "utils.h"
#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

mat mat_alloc_cols(size const m)
{
    return (mat)malloc(m*sizeof(vec));
}

mat mat_alloc(size const m, size const n)
{
    mat ret = mat_alloc_cols(m);
    for (idx i=0; i<m; ++i)
    {
        ret[i] = vec_alloc(n);
    }
    return ret;   
}

mat mat_zero(size const m, size const n)
{
    mat ret = (mat)malloc(m*sizeof(vec));
    for (idx i=0; i<m; ++i)
    {
        ret[i] = vec_zero(n);
    }
    return ret;
}

mat mat_identity(size const m, size const n)
{
    mat res = mat_zero(m, n);
    for (idx i = 0; i<smin(m,n); ++i) res[i][i] = (value)1;
    return res;
}

mat mat_copy(mat const a, size const m, size const n)
{
    mat ret = (mat)malloc(m*sizeof(vec));
    for (idx i=0; i<m; ++i)
    {
        ret[i] = vec_copy(a[i], n);
    }
    return ret;
}

void mat_scaleInp(mat a, value const s, size const m, size const n)
{
    for (idx i=0; i<m; ++i)
        for (idx j=0; j<n; ++j) 
            a[i][j] *= s;
}

void mat_addInp(mat a, mat const b, size const m, size const n)
{
    for (idx i=0; i<m; ++i)
        for (idx j=0; j<n; ++j) 
            a[i][j] += b[i][j];
}

void mat_subInp(mat a, mat const b, size const m, size const n)
{
    for (idx i=0; i<m; ++i)
        for (idx j=0; j<n; ++j) 
            a[i][j] -= b[i][j];
}

void mat_swap_lineInp(mat a, size const m, size const n, idx const i, idx const j)
{
    vec buff = a[i];
    a[i] = a[j];
    a[j] = buff;
}

void mat_swap_colInp(mat a, size const m, size const n, idx const i, idx const j)
{
    for (idx k=0; k<m; ++k)
    {
        value buff = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = buff;
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
    mat res = mat_zero(l, n);
    for (idx i=0; i<l; ++i)
    {
        for (idx k=0; k<n; ++k)
        {
            for (idx j=0; j<m; ++j)
            {
                res[i][k] += a[i][j] * b[j][k];
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
            trans[j][i] = a[i][j];
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
