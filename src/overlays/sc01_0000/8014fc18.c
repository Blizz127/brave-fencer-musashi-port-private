/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014FC18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80133784(s32 a0, void *a1, s32 a2);

s32 func_8014FC18(u8 *self)
{
    s16 src[4];
    s16 dst[4];
    s32 ret;
    src[0] = *(u16 *)(self + 0x6);
    src[1] = *(u16 *)(self + 0xA);
    src[2] = *(u16 *)(self + 0xE);
    dst[0] = *(u16 *)(self + 0x6);
    dst[1] = *(u16 *)(self + 0xA) + 0x10;
    dst[2] = *(u16 *)(self + 0xE);
    ret = func_80133784(1, src, (s32)dst);
    if (ret != 0) {
        *(u16 *)(self + 0x6) = dst[0];
        *(u16 *)(self + 0xA) = dst[1];
        *(u16 *)(self + 0xE) = dst[2];
        if (*(u8 *)&dst[3] != 0) {
            *(s16 *)(self + 0x16C) = *(u8 *)&dst[3];
        }
        *(s16 *)(self + 0x16E) = (u16)dst[3] >> 13;
        return ret;
    }
    if (*(u8 *)&dst[3] != 0) {
        *(s16 *)(self + 0x16C) = *(u8 *)&dst[3];
    }
    return 0;
}
