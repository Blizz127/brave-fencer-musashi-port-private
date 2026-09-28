/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0450 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { void (*fn)(void); } FnEntry;
extern s16 D_800D4C80;
extern FnEntry D_800D4C68[];

void func_800D0450(void) {
    if (D_800D4C80 < 5) {
        D_800D4C68[D_800D4C80].fn();
    }
}
