#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void **LRcroutCopy(double *A, int const n)
{
    for (int k=0; k<n-1; ++k)
    {
        double max = 0;
        int idx = 0;
        for(int j=0; j<n; ++j)
        {
            
            for (int i=0; i<j+1; ++i)
            {
                double sum = 0;
                for (int k=0; k<i; ++k)
                {
                    sum += A[i*n+k] * A[k*n+j];
                }
                A[i*n+j] = A[i*n+j] - sum;
            } 

            for (int i=j+1; i<n; ++i)
            {
                double sum = 0;
                for (int k=0; k<j; ++k)
                {
                    sum += A[i*n+k] * A[k*n+j];
                }
                A[i*n+j] = (A[i*n+j] - sum) / A[j*n+j];
            }
        }
    }
}

void **LRcroutCopy(double const *A, int const n)
{
    double *L = (double*)calloc(n*n, sizeof(double));
    double *R = (double*)calloc(n*n, sizeof(double));
    int *pi = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        pi[i] = i;
		L[i*n+i] = 1;
	}

    for (int k=0; k<n-1; ++k)
    {
        double max = 0;
        int idx = 0;
        for(int j=0; j<n; ++j)
        {
            
            for (int i=0; i<j+1; ++i)
            {
                double sum = 0;
                for (int k=0; k<i; ++k)
                {
                    sum += L[i*n+k] * R[k*n+j];
                }
                R[i*n+j] = A[i*n+j] - sum;
            } 

            for (int i=j+1; i<n; ++i)
            {
                double sum = 0;
                for (int k=0; k<j; ++k)
                {
                    sum += L[i*n+k] * R[k*n+j];
                }
                L[i*n+j] = (A[i*n+j] - sum) / R[j*n+j];
            }
        }
    }

    void **res = (void**)malloc(3*sizeof(void*));
    res[0] = L;
    res[1] = R;
    res[2] = pi;
    return res;
}

void Mperm(double *A, int const *pi, int const m, int const n)
{
    // n-1 permutations bring pi back to 1,2, ... ,n
    for (int i=0; i<n-1; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            // switch the two lines 
            double Abuff = A[i*m+j];
            A[i*m+j] = A[pi[i]*m+j];
            A[pi[i]*m+j] = Abuff;
        }
    }
}

double *MpermCopy(double const *A, int const *pi, int const m, int const n)
{
    double *newA = (double*)malloc(m*n*sizeof(double));
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            newA[i*m+j] = A[pi[i]*m+j];
        }
    }
    return newA;
}