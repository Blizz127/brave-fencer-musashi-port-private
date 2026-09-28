/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE908 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801ADA10();
extern void func_801AEAE4();
extern void func_801292C8(u8 *a0);

void func_801AE908(void *a0) {
    register s32 p __asm__("$4");
    u16 t;

    p = *(s32 *)((s32)a0 + 0x34);
    t = *(u16 *)(p + 0xC) - 0x400;
    *(u16 *)(p + 0xC) = t;
    *(u16 *)(p + 0x10) = t;
    if (*(s16 *)(p + 0xC) > 0) {
        *(s32 *)((s32)a0 + 0x1C) -= 1;
        if (*(s32 *)((s32)a0 + 0x1C) & 1) {
            func_801ADA10(a0);
        }
    } else {
        func_801AEAE4();
        func_801292C8((u8 *)a0);
    }
}
