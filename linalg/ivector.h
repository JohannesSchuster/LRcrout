#ifndef LINALG_IVECTOR_H
#define LINALG_IVECTOR_H

#include "defines.h"

ivec ivec_alloc(size const n);
ivec ivec_zero(size const n);
ivec ivec_unit(size const d, size const n);
ivec ivec_one(size const n);
ivec ivec_seq(size const n);

void ivec_seqInp(ivec a, size const n);
void ivec_scaleInp(ivec a, idx const s, size const n);
void ivec_addInp(ivec a, ivec const b, size const n);
void ivec_subInp(ivec a, ivec const b, size const n);
void ivec_swapInp(ivec a, size const n, idx const i, idx const j);

ivec ivec_copy(ivec const a, size const n);
ivec ivec_scale(ivec const a, idx const s, size const n);
ivec ivec_add(ivec const a, ivec const b, size const n);
ivec ivec_sub(ivec const a, ivec const b, size const n);
ivec ivec_swap(ivec const a, size const n, idx const i, idx const j);


void ivec_free(ivec a);

#endif // LINALG_IVECTOR_H