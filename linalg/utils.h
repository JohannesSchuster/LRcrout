#ifndef UTILS_H
#define UTILS_H

int imin(int const a, int const b);
int imax(int const a, int const b);
int iabs(int const a);

double dmin(double const a, double const b);
double dmax(double const a, double const b);
double dabs(double const a);

void **bind(int const n, ...);
void *get(void **elem, int const n);

#endif // UTILS_H