#include "utils.h"

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