#include "lr.h"

#include "../utils.h"
#include "../defines.h"
#include "../matvec.h"
#include <stdlib.h>

idx lr_checked_blockStepInp(mat A, size const n, idx const i, value const eps)
{
    //Check the pivot element, 
    if (vabs(A[i][i]) < eps)
    {
        //If too small A is singular
        return i;
    }

    for (idx j=i+1; j<n; ++j)
    {
        A[j][i] /= A[i][i];
        for (idx k=i+1; k<n; ++k)
        {
            A[j][k] -= A[j][i] * A[i][k];
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
            if (vabs(A[j][i]) > max)
            {
                max = A[j][i];
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

    ivec_invert_permutationInp(pi, n);

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
            if (vabs(A[i][j]) > max)
            {
                max = A[i][j];
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

    ivec_invert_permutationInp(pi, n);

    return SUCCESS;
}

idx lr_pivot_fullInp(mat A, ivec piL, ivec piC, size const n, value const eps)
{
    //Initialize p
    ivec_seqInp(piL, n);
    ivec_seqInp(piC, n);
    
    //Store the number of transpositions in pi[n]
    piL[n] = 0;
    piC[n] = 0;

    for (idx i=0; i<n; ++i)
    {
        value max = 0;
        idx pL = 0;
        idx pC = 0;
        for (idx j=i; j<n; ++j)
        {
            for (idx k=i; k<n; ++k)
            {
                if (vabs(A[j][k]) > max)
                {
                    max = A[j][k];
                    pL = j;
                    pC = k;
                }
            }
        }

        //Only swap lines when neccessary
        if (pL!=i)
        {
            //swap pi[p] and pi[i]
            ivec_swapInp(piL, n, i, pL);

            //swap cols A[1:n,i] and A[1:n,p]
            mat_swap_lineInp(A, n, n, i, pL);

            piL[n]++;
        }

        //Only swap cols when neccessary
        if (pC!=i)
        {
            //swap pi[p] and pi[i]
            ivec_swapInp(piC, n, i, pC);

            //swap cols A[1:n,i] and A[1:n,p]
            mat_swap_colInp(A, n, n, i, pC);

            piC[n]++;
        }

        idx res = lr_checked_blockStepInp(A, n, i, eps);
        if (res != SUCCESS) return res;
    }

    ivec_invert_permutationInp(piL, n);
    ivec_invert_permutationInp(piC, n);

    return SUCCESS;
}

mat split_lr(mat R, size const n)
{
    mat L = mat_identity(n, n);
    for (idx i=0; i<n; ++i)
    {
        for (idx j=0; j<i; ++j)
        {
            L[i][j] = R[i][j];
            R[i][j] = 0;
        }
    }
    return L;
}

//LR decomposition but don't override A
void **lr(mat const A, size const n, double const eps)
{
    //Copy A O(n2)
    mat R = mat_copy(A, n, n);

    //Do LR factorization on the copy O(n3)
    if (lrInp(R, n, eps) != SUCCESS)
    {
        mat_free(R, n);
        return NULL;
    }
    mat L = split_lr(R, n);
    
    //Create a suitable return type
    return bind(2, L, R);
}

void **lr_pivot_lines(mat const A, size const n, double const eps)
{
    mat R = mat_copy(A, n, n);
    ivec p = ivec_alloc(n+1);

    if (lr_pivot_linesInp(R, p, n, eps) != SUCCESS)
    {
        mat_free(R, n);
        ivec_free(p);
        return NULL;
    }

    mat L = split_lr(R, n);

    return bind(3, L, R, p);
}

void **lr_pivot_cols(mat const A, size const n, double const eps)
{
    mat R = mat_copy(A, n, n);
    ivec p = ivec_alloc(n+1);

    if (lr_pivot_colsInp(R, p, n, eps) != SUCCESS)
    {
        mat_free(R, n);
        ivec_free(p);
        return NULL;
    }

    mat L = split_lr(R, n);

    return bind(3, L, R, p);
}

void **lr_pivot_full(mat const A, size const n, value const eps)
{
    mat R = mat_copy(A, n, n);
    ivec pL = ivec_alloc(n+1);
    ivec pC = ivec_alloc(n+1);

    if (lr_pivot_fullInp(R, pL, pC, n, eps) != SUCCESS)
    {
        mat_free(R, n);
        ivec_free(pL);
        ivec_free(pC);
        return NULL;
    }

    mat L = split_lr(R, n);

    return bind(4, L, R, pL, pC);
}
