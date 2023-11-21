#include "lr.h"

#include "../utils.h"
#include "../defines.h"
#include <stdlib.h>

idx lr_checked_blockStepInp(mat A, size const n, idx const i, value const eps)
{
    //Check the pivot element, 
    if (vabs(A[i*n+i]) < eps)
    {
        //If too small A is singular
        return i;
    }

    for (idx j=i+1; j<n; ++j)
    {
        A[j*n+i] /= A[i*n+i];
        for (idx k=i+1; k<n; ++k)
        {
            A[j*n+k] -= A[j*n+i] * A[i*n+k];
        }
    }

    return SUCCESS;
}

//Normal LR decomposition
idx lrInp(mat A, size const n, double const eps)
{
    for (idx i = 0; i < n; ++i) 
    {
        idx res = lr_checked_blockStepInp(A, n, i, eps);
        if (res != SUCCESS) 
            return res;
    }
    return SUCCESS;
}

//LR decomposition with line permutation 
idx lr_pivot_linesInp(mat A, ivec pi, size const n, double const eps)
{
    //Initialize p
    ivec_seqInp(pi, n);

    //Store the number of transpositions in pi[n]
    pi[n] = 0;

    for (idx i=0; i<n; ++i)
    {
        value max = 0;
        idx p = 0;
        for (idx j=i; j<n; ++j)
        {
            if (vabs(A[j*n+i]) > max)
            {
                max = A[j*n+i];
                p = j;
            }
        }

        //Only swap when neccessary
        if (p!=i)
        {
            //swap pi[p] and pi[i]
            ivec_swapInp(pi, n, i, p);

            //swap lines A[p,1:n] and A[i,1:n]
            mat_swap_lineInp(A, n, n, i, p);

            pi[n]++;
        }

        idx res = lr_checked_blockStepInp(A, n, i, eps);
        if (res != SUCCESS) 
            return res;
    }

    return SUCCESS;
}

//LR decomposition with column permutation
idx lr_pivot_colsInp(mat A, ivec pi, size const n, double const eps)
{
    //Initialize p
    ivec_seqInp(pi, n);
    
    //Store the number of transpositions in pi[n]
    pi[n] = 0;

    for (idx i=0; i<n; ++i)
    {
        value max = 0;
        idx p = 0;
        for (idx j=i; j<n; ++j)
        {
            if (vabs(A[i*n+j]) > max)
            {
                max = A[i*n+j];
                p = j;
            }
        }

        //Only swap when neccessary
        if (p!=i)
        {
            //swap pi[p] and pi[i]
            ivec_swapInp(pi, n, i, p);

            //swap cols A[1:n,i] and A[1:n,p]
            mat_swap_colInp(A, n, n, i, p);

            pi[n]++;
        }

        idx res = lr_checked_blockStepInp(A, n, i, eps);
        if (res != SUCCESS) return res;
    }

    return SUCCESS;
}

//LR decomposition but don't override A
void **lr(mat const A, size const n, double const eps)
{
    //Copy A O(n2)
    mat R = mat_copy(A, n, n);

    //Do LR factorization on the copy O(n3)
    if (lrInp(R, n, eps) != SUCCESS)
    {
        free(R);
        return NULL;
    }
    mat L = mat_identity(n, n);

    //Split the matrices O(n2)
    for (idx i=0; i<n; ++i)
    {
        for (idx j=0; j<i; ++j)
        {
            L[i*n+j] = R[i*n+j];
            R[i*n+j] = 0;
        }
    }
    
    //Create a suitable return type
    return bind(2, L, R);
}

void **lr_pivot_lines(mat const A, size const n, double const eps)
{
    mat R = mat_copy(A, n, n);
    ivec p = ivec_alloc(n+1);

    if (lr_pivot_linesInp(R, p, n, eps) != SUCCESS)
    {
        free(R);
        free(p);
        return NULL;
    }

    mat L = mat_identity(n, n);

    //Split the matrices O(n2)
    for (idx i=0; i<n; ++i)
    {
        for (idx j=0; j<i; ++j)
        {
            L[i*n+j] = R[i*n+j];
            R[i*n+j] = 0;
        }
    }

    return bind(3, L, R, p);
}

void **lr_pivot_cols(mat const A, size const n, double const eps)
{
    mat R = mat_copy(A, n, n);
    ivec p = ivec_alloc(n+1);

    if (lr_pivot_colsInp(R, p, n, eps) != SUCCESS)
    {
        free(R);
        free(p);
        return NULL;
    }

    mat L = mat_identity(n, n);

    //Split the matrices O(n2)
    for (idx i=0; i<n; ++i)
    {
        for (idx j=0; j<i; ++j)
        {
            L[i*n+j] = R[i*n+j];
            R[i*n+j] = 0;
        }
    }

    return bind(3, L, R, p);
}
