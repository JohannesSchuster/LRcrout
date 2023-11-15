#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "linalg.h"
#include "printing.h"

// BEISPIELE
int n1 = 3;
double A1[] = {  2, 1,  1, 
                 4, 2, -1, 
                -1, 0,  7};
double b1[] = {1, 2, 3};
int pi1[] = {1, 2, 0};

int n2 = 5;
double A2[] = {  1,  0,  2,  0,  3,
                 0,  5,  1,  0,  0,
                 3,  0,  3,  2, -1,
                 0,  0,  0, -4,  2,
                 2, -1,  3,  0,  9};
double b2[] = {1, -1, 1, -1, 1};
int pi2[] = {2, 1, 4, 3, 0};

int main(void)
{
    mat A = A2;
    vec b = b2;
    ivec pi = pi2;
    int n = n2;
    double eps = 1e-16;

    mat_print(A, n, n);
    printf("\n");

    mat ALR = mat_copy(A, n, n);
    lrInp(ALR, n, eps);
    mat_print(ALR, n, n);
    printf("\n");

    void **LR = lr(A, n, eps);
    mat L = (mat)get(LR, 0);
    mat R = (mat)get(LR, 1);

    mat_print(L, n, n);
    printf("\n");

    mat_print(R, n, n);
    printf("\n");

    free(L);
    free(R);
    free(LR);

    return 0;
}