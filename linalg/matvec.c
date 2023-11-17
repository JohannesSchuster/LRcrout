#include "matvec.h"
#include "utils.h"

mat mat_diag(vec const d, size const m, size const n)
{
    mat res = mat_zero(m, n);
    for (idx i=0; i<smin(m,n); ++i)
    {
        res[i*m+i] = d[i];
    }
    return res;
}

vec mat_vec_mult(mat const A, vec const b, size const m, size const n)
{
    vec res = vec_zero(m);
    for (idx i=0; i<m; ++i)
    {
        for (idx j=0; j<n; ++j)
        {
            res[i] += A[i*n+j]*b[j];
        }
    }
}

void mat_permute_linesInp(mat a, ivec const p, size const m, size const n)
{
    for (idx i=0; i<m-1; ++i)
    {
        for (idx j=0; j<n; ++j)
        {
            double buff = a[p[i]*n+j];
            a[p[i]*n+j] = a[i*n+j];
            a[i*n+j] = buff;
        }
    }
}

void mat_permute_colsInp(mat a, ivec const p, size const m, size const n)
{
    for (idx j=0; j<n-1; ++j)
    {
        for (idx i=0; i<m; ++i)
        {
            double buff = a[i*n+p[j]];
            a[i*n+p[j]] = a[i*n+j];
            a[i*n+j] = buff;
        }
    }
}

mat mat_permute_lines(mat const a, ivec const p, size const m, size const n)
{
    mat perm = mat_copy(a, m, n);
    mat_permute_linesInp(perm, p, m, n);
    return perm;
}

mat mat_permute_cols(mat const a, ivec const p, size const m, size const n)
{
    mat perm = mat_copy(a, m, n);
    mat_permute_colsInp(perm, p, m, n);
    return perm;
}
