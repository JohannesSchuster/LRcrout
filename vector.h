#ifndef VECTOR_H
#define VECTOR_H

typedef double* vec;

vec zero(int const n);
vec unit(int const d, int const n);
vec one(int const n);

vec copy(vec const a, int const n);

void scaleInp(vec a, double const s, int const n);
void addInp(vec a, vec const b, int const n);
void subInp(vec a, vec const b, int const n);

vec scale(vec const a, double const s, int const n);
vec add(vec const a, vec const b, int const n);
vec sub(vec const a, vec const b, int const n);

double scalarProd(vec const a, vec const b, int const n);
double sqrNorm (vec const a, int const n);
double norm(vec const a, int const n);

double sqrDist(vec const a, vec const b, int const n);
double dist(vec const a, vec const b, int const n);

#endif // VECTOR_H