#include "printing.h"
#include "stdio.h"

void vec_print(vec const a, int const n)
{
    for (int i=0; i<n; ++i)
    {
        printf("%1.2lf ", a[i]);
    }
}

void mat_print(mat const a, int const m, int const n)
{
    for (int i=0; i<m; ++i)
    {
        vec_print(a+i*n, n);
        printf("\n");
    }
}