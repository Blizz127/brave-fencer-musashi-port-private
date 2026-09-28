/* SC02.CD member31 [8014F2E0,8014F3E8); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014F2E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801150D8;
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern u8 D_801202A0[];

s32 func_8014F2E0(s32 arg0, s16 * arg1, s16 * arg2)
{
    s32 ret = 0;
    u8 *s;
    for (s = D_801202A0; s < D_801202A0 + 0x6480; s += 0x10C) {
        if (*(u16 *)s != 0 &&
            *(s32 *)(s + 0x58) != 0 &&
            (s16 *)s != *(s16 **)(arg0 + 0x178) &&
            (s16 *)s != *(s16 **)(arg0 + 0x174) &&
            (*(s32 *)(s + 0x5C) & 0x1800) != 0) {
            D_801150D8 = 0;
            if (((s32 (*)(s32, s32, s32, s32))func_80135A4C)(((struct { s32 field; } *)(s + 0x20))->field,
                              ((struct { s32 field; } *)(s + 0x58))->field,
                              (s32)arg1, (s32)arg2) != 0) {
                ret = 1;
            }
        }
    }
    return ret;
}
