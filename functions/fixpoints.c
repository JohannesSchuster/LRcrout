#include "fixpoints.h"

#include <stdio.h>
#include <math.h>

double fixpoint(double(*fkt)(double), double const t0, int *flag, int *n, int const N, FILE *fptr, double const kappa, double const eps)
{
    int iter = 0;
    double t = t0;
    double oldT = t0;

    fprintf(fptr, "k |f(t_k)| t_k |t_k-1 - t_k| kov_order\n");
    while (1)
    {
        //Evaluate f at t and buffer the result
        double ft = fkt(t);

        //Calculate p
        double p = 1;
        if (iter > 1)
        {
            p = log10(fabs(ft - t))/log10(fabs(t - oldT));
        }
        
        // Test stopping criteria (1); iteration count
        if (iter++ > N)
        {
            *flag = 1;
            break;
        }

        // Test stopping criteria (2): divercence 
        if (iter > 1 && fabs(ft - t) > kappa*fabs(t - oldT))
        {
            *flag = 2;
            break;
        }

        // Test stopping criteria (3): f(t) approx t
        if (fabs(t - ft) < eps)
        {
            *flag = 3;
            break;
        }

        //print to debug file
        if (fptr) fprintf(fptr, "%i %18.16e %18.16e %18.16e %18.16e\n", iter, fabs(ft), ft, fabs(t - ft), p);

        //set the next t and old T;
        oldT = t;
        t = ft;
    }
    *n = iter;
    return t;
}

double newton(double(*fkt)(double), double(*der)(double), double const t0, int *flag, int *n, int const N, FILE *fptr, double const kappa, double const eps)
{
    int iter = 0;
    double t = t0;
    double oldT = t0;

    fprintf(fptr, "k |f(t_k)| t_k |t_k-1 - t_k| kov_order\n");
    while (1)
    {
        //Evaluate f and f' at t and buffer the results
        double ft = fkt(t);
        double dt = der(t);

        double newT = t - ft/dt;

        //Calculate p
        double p = 1;
        if (iter > 1)
        {
            p = log10(fabs(newT - t))/log10(fabs(t - oldT));
        }
        
        // Test stopping criteria (1); iteration count
        if (iter++ > N)
        {
            *flag = 1;
            break;
        }

        // Test stopping criteria (2): divercence 
        if (iter > 1 && fabs(newT - t) > kappa*fabs(t - oldT))
        {
            *flag = 2;
            break;
        }

        // Test stopping criteria (3): f(t) approx 0
        if (fabs(ft) < eps)
        {
            *flag = 3;
            break;
        }

        //print to debug file
        if (fptr) fprintf(fptr, "%i %18.16e %18.16e %18.16e %18.16e\n", iter, fabs(ft), newT, fabs(t - newT), p);

        //set the next t and old T;
        oldT = t;
        t = newT;
    }
    *n = iter;
    return t;
}

double secant(double(*fkt)(double), double const t0, double const t1, int *flag, int *n, int const N, FILE *fptr, double const kappa, double const eps)
{
    int iter = 0;
    double t = t1;
    double oldT = t0;

    double foldt = fkt(oldT);

    fprintf(fptr, "k |f(t_k)| t_k |t_k-1 - t_k| kov_order\n");
    while (1)
    {
        //Evaluate f and f' at t and buffer the results
        double ft = fkt(t);

        double newT = (oldT * ft - t * foldt) / (ft - foldt);

        //Calculate p for divergence criterea
        double p = log10(fabs(newT - t))/log10(fabs(t - oldT));

        // Test stopping criteria (1); iteration count
        if (iter++ > N)
        {
            *flag = 1;
            break;
        }

        // Test stopping criteria (2): divercence 
        if (iter > 1 && fabs(newT - t) > kappa*fabs(t - oldT))
        {
            *flag = 2;
            break;
        }

        // Test stopping criteria (3): f(t) approx 0
        if (fabs(ft) < eps)
        {
            *flag = 3;
            break;
        }

        //print to debug file
        if (fptr) fprintf(fptr, "%i %18.16e %18.16e %18.16e %18.16e\n", iter, fabs(ft), newT, fabs(t - newT), p);

        //set the next t and old t and f(old t);
        oldT = t;
        t = newT;   
        foldt = ft;
    }
    *n = iter;
    return t;
}