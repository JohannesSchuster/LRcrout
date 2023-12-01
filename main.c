#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define FUNCTIONS

#ifdef FUNCTIONS

#include "functions.h"

double h(double x)
{
    return x - exp(-0.5 * x);
}

double h_prime(double x)
{
    return 1 + 0.5 * exp(-0.5 * x);
}

double fix(double x)
{
    return x - h(x);
}

int main(void)
{
    double const eps = 1e-16;
    int const N = 100;
    double t0 = 0.8;
    double t1 = 0.7;
    double kappa = 0.5;
    const char filenameNewton[] = "debugNewton.txt";
    const char filenameFixpoint[] = "debugFixpoint.txt";
    const char filenameSecant[] = "debugSecant.txt";

    // Fixpoint iteration
    {
        FILE *file = fopen(filenameFixpoint, "w");
        if (!file) 
        {
            fprintf(stderr, "No file '%s' could be opened for writing.", filenameFixpoint);
            return -1;
        }

        int flag = 0;
        int iter = 0;
        printf("    x - h(%e)=%e}\n", t0, fix(t0));
        double fp = fixpoint(fix, t0, &flag, &iter, N, file, kappa, eps);
        fflush(file);
        fclose(file);
        printf("fixpoint iteration ");
        if (flag == 1)
        {
            printf("did not converge after %i iterations\n", iter);
        }
        if (flag == 2)
        {
            printf("diverged after %i iterations\n", iter);
        }
        if (flag == 3)
        {
            printf("converged after %i iterations\n", iter);
        }
        printf("    x - h(%e)=%e}\n", fp, fix(fp));
        printf("for debug information, see '%s'\n", filenameFixpoint);
    }

    // Newton's method
    {
        FILE *file = fopen(filenameNewton, "w");
        if (!file) 
        {
            fprintf(stderr, "No file '%s' could be opened for writing.", filenameNewton);
            return -1;
        }

        int flag = 0;
        int iter = 0;
        printf("    h(%e)=%e}\n", t0, h(t0));
        double zero = newton(h, h_prime, t0, &flag, &iter, N, file, kappa, eps);
        fflush(file);
        fclose(file);
        printf("newton iteration ");
        if (flag == 1)
        {
            printf("did not converge after %i iterations\n", iter);
        }
        if (flag == 2)
        {
            printf("diverged after %i iterations\n", iter);
        }
        if (flag == 3)
        {
            printf("converged after %i iterations\n", iter);
        }
        printf("    h(%e)=%e}\n", zero, h(zero));
        printf("for debug information, see '%s'\n", filenameNewton);
    }

    // Secant Method
    {
        FILE *file = fopen(filenameSecant, "w");
        if (!file) 
        {
            fprintf(stderr, "No file '%s' could be opened for writing.", filenameSecant);
            return -1;
        }

        int flag = 0;
        int iter = 0;
        printf("    h(%e)=%e}\n", t0, h(t0));
        double zero = secant(h, t0, t1, &flag, &iter, N, file, kappa, eps);
        fflush(file);
        fclose(file);
        printf("secant iteration ");
        if (flag == 1)
        {
            printf("did not converge after %i iterations\n", iter);
        }
        if (flag == 2)
        {
            printf("diverged after %i iterations\n", iter);
        }
        if (flag == 3)
        {
            printf("converged after %i iterations\n", iter);
        }
        printf("    h(%e)=%e}\n", zero, h(zero));
        printf("for debug information, see '%s'\n", filenameSecant);
    }

    return 0;
}

#endif

#ifdef LINALG
#include "linalg.h"
#include "printing.h"

// BEISPIELE
int n1 = 3;
double A1[] = {  2, 1,  1, 
                 4, 2, -1, 
                -1, 0,  7};
double b1[] = {1, 2, 3};
size_t pi1[] = {1, 2, 0, 0};

int n2 = 5;
double A2[] = {  1,  0,  2,  0,  3,
                 0,  5,  1,  0,  0,
                 3,  0,  3,  2, -1,
                 0,  0,  0, -4,  2,
                 2, -1,  3,  0,  9};
double b2[] = {1, -1, 1, -1, 1};
size_t pi2[] = {2, 1, 4, 3, 0};

int main(void)
{
    size n = n1;
    mat A = mat_copy_from_vec(A1, n, n);
    vec b = b1;
    ivec pi = pi1;
    value eps = 1e-16;

    void **LRp = lr_pivot_lines(A, n, eps);
    if (LRp)
    {
        mat_print(A, n, n);
        printf("\n");
  
        mat L = get(LRp, 0);
        mat R = get(LRp, 1);
        ivec p = get(LRp, 2);

        ivec_print(p, n+1);
        printf("\n");
  
        mat_print(L, n, n);
        printf("\n");
  
        mat_print(R, n, n);
        printf("\n");

        mat PA = mat_permute_lines(A, p, n, n);
        mat_print(PA, n, n);
        printf("\n");

        mat Arek = mat_mult(L, R, n, n, n);
        mat_print(Arek, n, n);
        printf("\n");
  
        mat_free(L, n);
        mat_free(R, n);
        free(LRp);
        mat_free(PA, n);
        mat_free(Arek, n);
    }

//    mat PA = mat_permute_lines(A, pi, n, n);
//    void **LR = lr(PA, n, eps);
//    if (LR)
//    {
//        mat_print(PA, n, n);
//        printf("\n");
//
//        mat L = (mat)get(LR, 0);
//        mat R = (mat)get(LR, 1);
//
//        mat_print(L, n, n);
//        printf("\n");
//
//        mat_print(R, n, n);
//        printf("\n");
//
//        mat Arek = mat_mult(L,R,n,n,n);
//        mat_print(Arek, n, n);
//        printf("\n");
//
//        free(PA);
//        free(L);
//        free(R);
//        free(LR);
//        free(Arek);
//    }

    return 0;
}
#endif