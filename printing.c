#include "printing.h"
#include "stdio.h"

void vec_print(vec const a, size const n)
{
    for (idx i=0; i<n; ++i)
    {
        printf("%1.2lf ", a[i]);
    }
    printf("\n");
}

void ivec_print(ivec const a, size const n)
{
    for (idx i=0; i<n; ++i)
    {
        printf("%lu ", a[i]);
    }
    printf("\n");
}

void mat_print(mat const a, size const m, size const n)
{
    for (idx i=0; i<m; ++i)
    {
        vec_print(a[i], n);
    }
}