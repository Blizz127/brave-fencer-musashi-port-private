/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2D78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801AFDF4[])(void);
extern void func_801A4258(void);
extern void func_801A3F10(void);

void func_801A2D78(void *a0) {
    D_801AFDF4[*(u16 *)((s32)a0 + 0x2)]();
    func_801A4258();
    func_801A3F10();
}
