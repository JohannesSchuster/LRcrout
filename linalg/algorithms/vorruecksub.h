#ifndef LINALG_ALGORITHMS_VORRUECKSUB_H
#define LINALG_ALGORITHMS_VORRUECKSUB_H

#include "../defines.h"
#include "../vector.h"
#include "../matrix.h"

void vwsubInp(mat const L, vec b, size const n);
void rwsubInp(mat const R, vec b, size const n);

vec vwsub(mat const L, vec const b, size const m, size const n, value const eps);
vec rwsub(mat const R, vec const b, size const m, size const n, value const eps);

#endif // LINALG_ALGORITHMS_VORRUECKSUB_H