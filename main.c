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
    int n = n2;
    int *pi = pi2;

    return 0;
}