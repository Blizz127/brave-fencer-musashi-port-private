/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3FB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801439C0(u8 *a0);

void func_801A3FB0(void *arg0) {
    register void *s0 __asm__("$16");
    register u8 *a0 __asm__("$4");
    s32 *v0p;

    s0 = arg0;
    v0p = *(s32 **)((char *)s0 + 0x20);
    *(s32 *)((char *)v0p + 4) |= 0x80000000;

    a0 = *(u8 **)((char *)s0 + 0xD0);
    if (a0 != NULL) {
        func_801439C0(a0);
        *(u8 **)((char *)s0 + 0xD0) = NULL;
    }
}
