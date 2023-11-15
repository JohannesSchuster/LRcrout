#include "utils.h"

#include <stdlib.h>
#include <stdarg.h>

int imin(int const a, int const b)
{
    return (a < b ? a : b);
}

int imax(int const a, int const b)
{
    return (a > b ? a : b);
}

int iabs(int const a)
{
    return (a < 0 ? -a : a);
}

double dmin(double const a, double const b)
{
    return (a < b ? a : b);
}

double dmax(double const a, double const b)
{
    return (a > b ? a : b);
}

double dabs(double const a)
{
    return (a < 0 ? -a : a);
}

void **bind(int const n, ...)
{
    void **ret = (void**)malloc(n*sizeof(void*));
    va_list args;
    va_start(args, n);
    for (int i=0; i<n; ++i)
    {
        ret[i] = va_arg(args, void*);
    }
    va_end(args);
    return ret;
}

void *get(void **elem, int const n)
{
    return elem[n];
}