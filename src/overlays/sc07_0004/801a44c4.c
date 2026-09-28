/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A44C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C31C(void);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_801A44C4(s32 a0) {
    s32 v0;
    s32 v1;
    s16 sp[10];

    if (a0 != 0 && *(u16 *)a0 != 0) {
        sp[0] = *(u16 *)(a0 + 0x6);
        sp[1] = *(u16 *)(a0 + 0xA);
        sp[2] = *(u16 *)(a0 + 0xE);
    } else {
        sp[2] = 0;
        sp[1] = 0;
        sp[0] = 0;
    }
    sp[3] = 0x332;
    sp[5] = 0;
    sp[4] = 0;
    *(s32 *)&sp[8] = 0;
    sp[7] = 0;
    sp[6] = 0x7FFF;
    v0 = func_8012C31C();
    if (v0 != 0) {
        v1 = func_8012C890((s32)&sp[0], v0, a0);
    } else {
        v1 = 0;
    }
    return v1;
}
