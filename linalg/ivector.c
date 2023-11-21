#include "ivector.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

ivec ivec_alloc(size const n)
{
    return (ivec)malloc(n*sizeof(idx));
}

ivec ivec_zero(size const n)
{
    return (ivec)calloc(n, sizeof(idx));
}

ivec ivec_unit(size const d, size const n)
{
    ivec res = ivec_zero(n);
    res[d] = 1;
    return res;
}

ivec ivec_one(size const n)
{
    ivec res = ivec_alloc(n);
    memset(res, (idx)1, n*sizeof(idx));
    return res;
}

ivec ivec_seq(size const n)
{
    ivec res = ivec_alloc(n);
    ivec_seqInp(res, n);
    return res;
}

ivec ivec_copy(ivec const a, size const n)
{
    ivec res = ivec_alloc(n);
    memcpy(res, a, n*sizeof(idx));
}

void ivec_seqInp(ivec a, size const n)
{
    for (idx i=0; i<n; ++i) a[i] = i;
}

void ivec_scaleInp(ivec a, idx const s, size const n)
{
    for (idx i=0; i<n; ++i) a[i] *= s;
}

void ivec_addInp(ivec a, ivec const b, size const n)
{
    for (idx i=0; i<n; ++i) a[i] += b[i];
}

void ivec_subInp(ivec a, ivec const b, size const n)
{
    for (idx i=0; i<n; ++i) a[i] -= b[i];
}

void ivec_swapInp(ivec a, size const n, idx const i, idx const j)
{
    idx buff = a[i];
    a[i] = a[j];
    a[j] = buff;
}

ivec ivec_scale(ivec const a, idx const s, size const n)
{
    ivec res = ivec_copy(a, n);
    ivec_scaleInp(res, s, n);
    return res;
}

ivec ivec_add(ivec const a, ivec const b, size const n)
{
    ivec res = ivec_copy(a, n);
    ivec_addInp(res, b, n);
    return res;
}

ivec ivec_sub(ivec const a, ivec const b, size const n)
{
    ivec res = ivec_copy(a, n);
    ivec_subInp(res, b, n);
    return res;
}

ivec ivec_swap(ivec const a, size const n, idx const i, idx const j)
{
    ivec ret = ivec_copy(a,n);
    ivec_swapInp(a, n, i, j);
    return ret;
}
