/* Complete SC02 state-0 wrapper; independently matched ordinary C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181A24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8012AD50(void *a0);

/* B28: the retail body leaves a0 untouched, so 8012AD50 receives this
 * function's own first argument (the object it updates). Byte-identical
 * (gcc-2.7.2-psx -O2). */
void func_80181A24(void *arg0) {
        func_8012AD50(arg0);
    }
