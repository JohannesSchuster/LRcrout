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