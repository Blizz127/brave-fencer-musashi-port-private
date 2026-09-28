/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CEE74 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
typedef struct { void (*fn)(void); } FnEntry;
extern FnEntry D_800D4C54[];

void func_800CEE74(void) {
    register u8 *base = (u8 *)D_800AF630;
    if (*(u16 *)(base + 0xA3B4) < 5u) {
        D_800D4C54[*(u16 *)(base + 0xA3B4)].fn();
    }
}
