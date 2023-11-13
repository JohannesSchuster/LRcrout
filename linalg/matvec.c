#include "matvec.h"

vec mat_vec_mult(mat const A, vec const b, int const m, int const n)
{
    vec res = vec_zero(m);
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            res[i] += A[i*n+j]*b[j];
        }
    }
}

void mat_permute_lines(mat a, ivec const p, int const m, int const n)
{
    for (int i=0; i<m-1; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            double buff = a[p[i]*n+j];
            a[p[i]*n+j] = a[i*n+j];
            a[i*n+j] = buff;
        }
    }
}

void mat_permute_cols(mat a, ivec const p, int const m, int const n)
{
    for (int j=0; j<n-1; ++j)
    {
        for (int i=0; i<m; ++i)
        {
            double buff = a[i*n+p[j]];
            a[i*n+p[j]] = a[i*n+j];
            a[i*n+j] = buff;
        }
    }
}