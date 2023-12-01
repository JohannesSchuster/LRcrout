#ifndef FUNCTIONS_FIXPOINTS_H
#define FUNCTIONS_FIXPOINTS_H

#include <stdio.h>

double fixpoint(double(*fkt)(double), double const t0, 
                int *flag, int *n, int const N,
                FILE *fptr,
                double const kappa, double const eps);

double newton(double(*fkt)(double), double(*der)(double), double const t0, 
                int *flag, int *n, int const N, 
                FILE *fptr,
                double const kappa, double const eps);

double secant(double(*fkt)(double), double const t0, double const t1,
                int *flag, int *n, int const N, 
                FILE *fptr,
                double const kappa, double const eps);

#endif // FUNCTIONS_FIXPOINTS_H