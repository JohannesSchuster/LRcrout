#ifndef LINALG_ALGORITHMS_VORRUECKSUB_H
#define LINALG_ALGORITHMS_VORRUECKSUB_H

#include "../defines.h"
#include "../vector.h"
#include "../matrix.h"

idx vwsubInp(mat const L, vec b, size const m, size const n);
idx rwsubInp(mat const R, vec b, size const m, size const n);

vec vwsub(mat const L, vec const b, size const m, size const n);
vec rwsub(mat const R, vec const b, size const m, size const n);

#endif // LINALG_ALGORITHMS_VORRUECKSUB_H