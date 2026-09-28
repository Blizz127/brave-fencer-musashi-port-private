/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB78C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801292C8(u8 *a0);
extern u8 D_801F88BA;

void func_801AB78C(void *a0) {
    register volatile u8 *p __asm__("$5") = &D_801F88BA;
    register s32 b __asm__("$3");
    s32 t;
    if (*p == 0) {
        func_801292C8((u8 *)a0);
    } else {
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) += 0x200;
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);
        b = *p;
        t = b - 0x10;
        if (b != 0) {
            b = t;
            if (t < 0) {
                b = 0;
            }
            *p = (u8)b;
        }
    }
}
