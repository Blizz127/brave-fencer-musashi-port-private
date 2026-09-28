/* Complete SC02 retail dispatch [801843B4,801843F0); C recovery pending. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801843B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801AB130[])(void);

void func_801843B4(void *a0) {
    D_801AB130[*(u16 *)((s32)a0 + 0x2)]();
}
