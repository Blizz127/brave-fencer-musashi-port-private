/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A419C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 *aD_80126B78 __asm__("D_80126B78");
extern u8 D_800D3918[];
extern u8 D_801A68F4[];
extern u8 D_801152A8[];
extern s32 D_80127078;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012B2CC(s32 a0);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

s32 func_801A419C(s32 arg0) {
    s32 buf[2];   /* 0x18(sp): projected point A */
    s32 out[2];   /* 0x20(sp): projected point B */

    func_8012F14C((s32)aD_80126B78 + 0x34, (s32)D_800D3918, (s32)buf);
    func_8012F14C((s32)aD_80126B78 + 0x34, (s32)D_801A68F4, (s32)out);
    func_8012B2CC(arg0);
    if (func_80135888(*(s32 *)(arg0 + 0x20), *(s32 *)(arg0 + 0x58), (s32)buf, (s32)out) != 0) {
        func_8012F568(1, 0x1C,
                      *(u16 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x12) & 0xFFF,
                      0x1E, (s32)out, (s32)D_801152A8);
        D_80127078 = arg0;
        return 1;
    }
    return 0;
}
