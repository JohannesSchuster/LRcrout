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
    mat A = A1;
    vec b = b1;
    ivec pi = pi1;
    int n = n1;
    double eps = 1e-16;

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
  
        free(L);
        free(R);
        free(LRp);
        free(PA);
        free(Arek);
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