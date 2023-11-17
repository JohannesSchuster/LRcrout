#ifndef UTILS_H
#define UTILS_H

#include "defines.h"

size smin(size const a, size const b);
size smax(size const a, size const b);
int iabs(int const a);

value vmin(value const a, value const b);
value vmax(value const a, value const b);
value vabs(value const a);

void **bind(size const n, ...);
void *get(void **elem, idx const n);

#endif // UTILS_H