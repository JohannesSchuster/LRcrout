#ifndef LINALG_SOLVER_LR_H
#define LINALG_SOLVER_LR_H

#include "../defines.h"
#include "../vector.h"
#include "../ivector.h"
#include "../matrix.h"

idx lrInp(mat A, size const n, value const eps);
idx lr_pivot_colsInp(mat A, ivec pi, size const n, value const eps);
idx lr_pivot_linesInp(mat A, ivec pi, size const n, value const eps);

void **lr(mat const A, size const n, value const eps);
void **lr_pivot_lines(mat const A, size const n, value const eps);
void **lr_pivot_cols(mat const A, size const n, value const eps);

#endif // LINALG_SOLVER_LR_H