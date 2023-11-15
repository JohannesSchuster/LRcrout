#ifndef LINALG_MATRIX_H
#define LINALG_MATRIX_H

typedef double* mat;

mat mat_alloc(int const m, int const n);
mat mat_zero(int const m, int const n);
mat mat_identity(int const m, int const n);
mat mat_copy(mat const a, int const m, int const n);

void mat_scaleInp(mat a, double const s, int const m, int const n);
void mat_addInp(mat a, mat const b, int const m, int const n);
void mat_subInp(mat a, mat const b, int const m, int const n);

mat mat_scale(mat const a, double const s, int const m, int const n);
mat mat_add(mat const a, mat const b, int const m, int const n);
mat mat_sub(mat const a, mat const b, int const m, int const n);
mat mat_mult(mat const a, mat const b, int const l, int const m, int const n);

mat mat_trans(mat const a, int const m, int const n);

#endif // LINALG_MATRIX_H