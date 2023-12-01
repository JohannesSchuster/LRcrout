#ifndef FUNCTIONS_FIXPOINTS_H
#define FUNCTIONS_FIXPOINTS_H

#include <stdio.h>

//Calculates a fixpoint of a given one-dimensional function
//  t = f(t), with starting value t0
//using the Bannach fixpoint iteration. If fptr is nut NULL
//additional debug information will be written to fptr in 
//each iteration.
//The algorith terminates if:
//  (1) the number of iterations exceeds a maximum N
//  (2) the prucess diverges (controlled by kappa)
//  (3) a siutably accurate solution t is found (controlled by eps)
//the parameter flag will hold information which criterion was met.
//
//Inputs:
//  fkt:   double(*)(double)   function pointer to f
//  t0:    double const        starting value
//  flag:  int*                pointer to termination flag
//  n:     int*                pointer to the used number if iterations
//  N:     int                 max iterations
//  fptr   FILE*               pointer to the output file
//  kappa  double const        contraction number
//  eps    double const        error tolerance
//
//Outputs:
//  t      double              the calculated fixpoint
double fixpoint(double(*fkt)(double), double const t0, 
                int *flag, int *n, int const N,
                FILE *fptr,
                double const kappa, double const eps);

//Calculates a root of a given one-dimensional function
//  f(t) = 0, with starting value t0
//using the Newton iteration. If fptr is nut NULL
//additional debug information will be written to fptr in 
//each iteration.
//The algorith terminates if:
//  (1) the number of iterations exceeds a maximum N
//  (2) the prucess diverges (controlled by kappa)
//  (3) a siutably accurate solution t is found (controlled by eps)
//the parameter flag will hold information which criterion was met.
//
//Inputs:
//  fkt:   double(*)(double)   function pointer to f
//  der:   double(*)(double)   function pointer to f'
//  t0:    double const        starting value
//  flag:  int*                pointer to termination flag
//  n:     int*                pointer to the used number if iterations
//  N:     int                 max iterations
//  fptr   FILE*               pointer to the output file
//  kappa  double const        contraction number
//  eps    double const        error tolerance
//
//Outputs:
//  t      double              the calculated root
double newton(double(*fkt)(double), double(*der)(double), double const t0, 
                int *flag, int *n, int const N, 
                FILE *fptr,
                double const kappa, double const eps);

//Calculates a root of a given one-dimensional function
//  f(t) = 0, with starting value t0
//using the Secant algorithm. If fptr is nut NULL
//additional debug information will be written to fptr in 
//each iteration.
//The algorith terminates if:
//  (1) the number of iterations exceeds a maximum N
//  (2) the prucess diverges (controlled by kappa)
//  (3) a siutably accurate solution t is found (controlled by eps)
//the parameter flag will hold information which criterion was met.
//
//Inputs:
//  fkt:   double(*)(double)   function pointer to f
//  t0:    double const        starting value 0
//  t1:    double const        starting value 1
//  flag:  int*                pointer to termination flag
//  n:     int*                pointer to the used number if iterations
//  N:     int                 max iterations
//  fptr   FILE*               pointer to the output file
//  kappa  double const        contraction number
//  eps    double const        error tolerance
//
//Outputs:
//  t      double              the calculated root
double secant(double(*fkt)(double), double const t0, double const t1,
                int *flag, int *n, int const N, 
                FILE *fptr,
                double const kappa, double const eps);

#endif // FUNCTIONS_FIXPOINTS_H