/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5BBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A4FB4(u8 *, s8);
extern void func_800233CC(void *, u16);
extern void func_801292C8(u8 *);
extern u8 D_801F4448[];

void func_801A5BBC(s32 arg0) {
    s16 var;

    var = *(s16 *)(arg0 + 0x2C);
    if (var < 0x700) {
        *(s16 *)(arg0 + 0x2C) = var + 0x30;
        func_801A4FB4(D_801F4448, -4);
        func_800233CC(D_801F4448 - 4, *(u16 *)(arg0 + 0x2C));
    } else {
        func_801292C8((u8 *)arg0);
    }
}
