#include "lr.h"

#include "../utils.h"
#include <stdio.h>

//Normal LR decomposition
void lrInp(mat A, int const n, double const eps)
{
    // Decomposing matrix into Upper and Lower
    // triangular matrix
    for (int i = 1; i < n; ++i) 
    {
        // Upper Triangular
        for (int j = i; j < n; ++j)
        {
            // Summation of L(i, j) * U(j, k)
            double sum = 0;
            for (int k = 0; k < i-1; ++k)
            {
                sum += (A[i*n+k] * A[k*n+j]);
            }
            A[i*n+j] -= sum;
        }
 
        // Lower Triangular
        for (int j = i+1; j < n; ++j) 
        {
            // Summation of L(k, j) * U(j, i)
            double sum = 0;
            for (int k = 1; k < i-1; ++k)
            {
                sum += (A[i*n+k] * A[k*n+j]);
            }
            if (dabs(A[i*n+i]) < eps)
            {
                printf("LR: Diagonal element %i too small (%lf), aborted!\n", i+1, A[i*n+i]);
                return;
            }

            // Evaluating L(k, i)
            A[j*n+i] = (A[i*n+j] - sum) / A[i*n+i];
        }
    }
}

//LR decomposition with row permutation 
// void lr_pivot_colsInp(mat A, ivec p, int const n, double const eps)
// {
// 
// }

//LR decomposition with line permutation
// void lr_pivot_linesInp(mat A, ivec p, int const n, double const eps)
// {
// 
// }

//LR decomposition but don't override A
void **lr(mat const A, int const n, double const eps)
{
    //Copy A O(n2)
    mat R = mat_copy(A, n, n);

    //Do LR factorization on the copy O(n3)
    lrInp(R, n, eps);
    mat L = mat_identity(n, n);

    //Split the matrices O(n2)
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<i; ++j)
        {
            L[i*n+j] = R[i*n+j];
            R[i*n+j] = 0;
        }
    }
    
    //Create a suitable return type
    void **ret = (void**)malloc(2*sizeof(void*));
    ret[0] = (void*)L;
    ret[1] = (void*)R;
    return ret;
}
