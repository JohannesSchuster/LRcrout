#include "matvec.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

mat mat_diag(vec const d, size const m, size const n)
{
    mat res = mat_zero(m, n);
    for (idx i=0; i<smin(m, n); ++i)
    {
        res[i][i] = d[i];
    }
    return res;
}

mat mat_from_vec(vec const a, size const m, size const n)
{
    mat res = (mat)malloc(m*sizeof(vec));
    for (idx i=0; i<m; ++i)
    {
        res[i] = a+i*n;
    }
    return res;
}

mat mat_copy_from_vec(vec const a, size const m, size const n)
{
    mat res = (mat)malloc(m*sizeof(vec));
    for (idx i=0; i<m; ++i)
    {
        res[i] = vec_copy(a+i*n, n);
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
            res[i] += A[i][j] * b[j];
        }
    }
}

void vec_permuteInp(vec a, ivec const p, size const n)
{
    ivec pi = ivec_copy(p, n);
    for (idx i=0; i<n-1; ++i)
    {
        vec_swapInp(a, n, i, pi[i]);
        ivec_swapInp(pi, n, i, pi[i]);
    }
    free(pi);
}

vec vec_permute(vec const a, ivec const p, size const n)
{
    vec res = vec_copy(a, n);
    vec_permuteInp(res, p, n);
    return res;
}

void ivec_permuteInp(ivec a, ivec const p, size const n)
{
    ivec pi = ivec_copy(p, n);
    for (idx i=0; i<n; ++i)
    {
        ivec_swapInp(a, n, i, pi[i]);
        ivec_swapInp(pi, n, i, pi[i]);
    }
    free(pi);
}

ivec ivec_permute(ivec const a, ivec const p, size const n)
{
    ivec res = ivec_copy(a, n);
    ivec_permuteInp(res, p, n);
    return res;
}

void ivec_invert_permutationInp(ivec a, size const n)
{
    ivec pi = ivec_copy(a, n);
    for (idx i=0; i<n; ++i) a[pi[i]] = i;
    ivec_free(pi);
}


ivec ívec_invert_permutation(ivec const a, size const n)
{
    ivec inv = ivec_alloc(n);
    ivec_invert_permutationInp(inv, n);
    return inv;
}

void mat_permute_linesInp(mat a, ivec const p, size const m, size const n)
{
    ivec pi = ivec_copy(p, m);
    for (idx i=0; i<m; ++i)
    {
        mat_swap_lineInp(a, m, n, i, pi[i]);
        ivec_swapInp(pi, m, i, pi[i]);
    }
    free(pi);
}

void mat_permute_colsInp(mat a, ivec const p, size const m, size const n)
{
    ivec pi = ivec_copy(p, n);
    for (idx j=0; j<n-1; ++j)
    {
        mat_swap_colInp(a, m, n, j, pi[j]);
        ivec_swapInp(pi, m, j, pi[j]);
    }
    free(pi);
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

void mat_free(mat a, size const m)
{
    for (idx i=0; i<m; ++i) free(a[i]);
    free(a);
}
