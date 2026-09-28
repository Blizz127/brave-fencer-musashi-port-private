/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801653F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80165624(s32 a0);
extern u8 D_80078EC1;
extern u8 D_80078EC5;
extern s16 D_800B9A08;

void func_801653F4(s32 a0) {
    s32 loc;
    s32 v;
    loc = D_800B9A08;
    D_80078EC5 = 0;
    v = D_80078EC1 & 0x7F;
    D_80078EC1 = v;
    if (func_80165624(a0) != 0) {
        D_80078EC5 = 0x80;
        return;
    }
    if (D_80078EC1 != 0x1A) {
        return;
    }
    if ((u32)(loc - 0x305C) < 2) return;
    if ((u32)(loc - 0x305E) < 2) return;
    if ((u32)(loc - 0x3060) < 2) return;
    if ((u32)(loc - 0x3062) < 2) return;
    if ((u32)(loc - 0x3064) < 2) return;
    if (loc == 0x3066) return;
    D_80078EC5 = 0x80;
}
