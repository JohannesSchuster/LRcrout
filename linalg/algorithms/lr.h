#ifndef LINALG_SOLVER_LR_H
#define LINALG_SOLVER_LR_H

#include "../vector.h"
#include "../matrix.h"

int lrInp(mat A, int const n, double const eps);
int lr_pivot_colsInp(mat A, ivec pi, int const n, double const eps);
int lr_pivot_linesInp(mat A, ivec pi, int const n, double const eps);

void **lr(mat const A, int const n, double const eps);
void **lr_pivot_lines(mat const A, int const n, double const eps);
void **lr_pivot_cols(mat const A, int const n, double const eps);

#endif // LINALG_SOLVER_LR_H