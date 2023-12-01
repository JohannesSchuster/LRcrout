#ifndef LINALG_DEFINES_H
#define LINALG_DEFINES_H

#include <stddef.h>

#define SUCCESS ((idx)(-1))

typedef size_t idx;
typedef size_t size;
typedef double value;

typedef value* vec;
typedef idx* ivec;
typedef value** mat;

#endif // LINALG_DEFINES_H