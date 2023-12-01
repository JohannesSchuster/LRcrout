#include "vorruecksub.h"
#include "../matvec.h"

#include "../utils.h"
#include <stdlib.h>

void vwsubInp(mat const L, vec b, size const n)
{
    //Calculate x s.t. L*x=b, where L is a lower triangular matrix
    //and store the solution in b
    for (idx i = 0; i<n; ++i)
    {
        for (idx j = 0; j < i; ++j)
        {
            b[i] -= L[i][j] * b[j];
        }
        b[i] /= L[i][i];
    }
}

void rwsubInp(mat const R, vec b, size const n)
{
    //Calculate x s.t. R*x=b, where R is an upper triangular matrix
    //and store the solution in b
    for (idx i = n-1; i>=0; --i)
    {
        for (idx j = i; j < n; ++j)
        {
            b[i] -= R[i][j] * b[j];
        }
        b[i] /= R[i][i];
    }
}

vec vwsub(mat const L, vec const b, size const m, size const n, value const eps)
{
    //For now assume m >= n
    vec x = vec_copy(b, n);
    //Do the vwsub in place of x
    vwsubInp(L, x, n);
    //Check if the solution x satisfies || L*x-b || < eps
    value rest = 0;
    for (idx i=n; i<m; ++i)
    {
        for (idx j=0; j<n; ++j)
        {
            value diff = (L[i][j]*x[j]-b[i]);
            rest += diff*diff;
        }
    }
    if (rest > eps*eps)
    {
        return NULL;
    }
    return x;
}

vec rwsub(mat const R, vec const b, size const m, size const n, value const eps)
{
    //For now assume 
    vec x = vec_copy(b, n);
    //Do the vwsub in place of x
    rwsubInp(R, x, n);
    //Check if the solution x satisfies L*x=b for the remaining lines
    for (idx i = n; i<m; ++i)
    {
        value check = 0;
        for (idx j = 0; j < i; ++j)
        {
            check += R[i][j] * x[j];
        }
        if (vabs(check - b[i]) > eps)
        {
            // x does not satisfy L*x=b
            free(x);
            return NULL;
        }
    }
    return x;
}