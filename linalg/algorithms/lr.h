#ifndef LINALG_SOLVER_LR_H
#define LINALG_SOLVER_LR_H

#include "../vector.h"
#include "../matrix.h"

void lrInp(mat A, int const n, double const eps);
// void lr_pivot_colsInp(mat A, ivec p, int const n, double const eps);
// void lr_pivot_linesInp(mat A, ivec p, int const n, double const eps);

//TODO: Implement these
void **lr(mat const A, int const n, double const eps);
// void **lr_pivot_lines(mat const A, int const m, int const n, double const eps);
// void **lr_pivot_cols(mat const A, int const m, int const n, double const eps);

#endif // LINALG_SOLVER_LR_H