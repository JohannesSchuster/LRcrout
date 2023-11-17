#include "utils.h"

#include <stdlib.h>
#include <stdarg.h>

size smin(size const a, size const b)
{
    return (a < b ? a : b);
}

size smax(size const a, size const b)
{
    return (a > b ? a : b);
}

int iabs(int const a)
{
    return (a < 0 ? -a : a);
}

value vmin(value const a, value const b)
{
    return (a < b ? a : b);
}

value vmax(value const a, value const b)
{
    return (a > b ? a : b);
}

value vabs(value const a)
{
    return (a < 0 ? -a : a);
}

void **bind(size const n, ...)
{
    void **ret = (void**)malloc(n*sizeof(void*));
    va_list args;
    va_start(args, n);
    for (idx i=0; i<n; ++i)
    {
        ret[i] = va_arg(args, void*);
    }
    va_end(args);
    return ret;
}

void *get(void **elem, idx const n)
{
    return elem[n];
}