#ifndef BLATT_4_h
#define BLATT_4_h

void LRcrout(double *A, int const n);
void **LRcroutCopy(double const *A, int const n);
void Mperm(double *A, int const *pi, int const m, int const n);
double *MpermCopy(double const*A, int const *pi, int const m, int const n);

#endif // BALTT_4_h