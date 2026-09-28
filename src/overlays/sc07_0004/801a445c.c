/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A445C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8019FF8A;
extern void func_801A9C00(void *a0);

void func_801A445C(void *arg0) {
    u16 v0;
    s32 v1;

    v0 = *(u16 *)((u8 *)arg0 + 0x5C);
    v1 = *(s16 *)((u8 *)arg0 + 0xFE);
    *(u8 *)((u8 *)arg0 + 0xC1) = 0;
    *(u16 *)((u8 *)arg0 + 0x5E) = 0;
    *(u16 *)((u8 *)arg0 + 0x5C) = v0 & 0xFFFE;
    if (v1 == 0) {
        if ((D_8019FF8A & 0x200) == 0) {
            func_801A9C00(arg0);
            *(s16 *)((u8 *)arg0 + 0xFE) = 8;
        }
    }
}
