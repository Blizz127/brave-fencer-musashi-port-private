/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E5B0,8015E698).
 * Offset 0x36458 at overlay base 80128158. SHA256(span)=e11532cc55127cd2bf4dd3e4c9a17716f6df2bc22fbdc23759dae859404e0dd6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e5b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E5B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

void func_8015E5B0(u8 *self)
{
    u8 *obj;
    s16 src[4];
    s16 dst[4];
    obj = *(u8 **)(self + 0x18C);
    if (obj == 0) {
        return;
    }
    src[0] = *(u16 *)(self + 0x6);
    src[1] = *(u16 *)(self + 0xA) - 0x14;
    src[2] = *(u16 *)(self + 0xE);
    dst[0] = *(u16 *)(obj + 0x6);
    dst[1] = *(u16 *)(obj + 0xA);
    dst[2] = *(u16 *)(obj + 0xE);
    if (func_80133784(0, src, (s32)dst) != 0) {
        *(u16 *)(obj + 0x6) = dst[0];
        *(u16 *)(obj + 0xA) = dst[1];
        *(u16 *)(obj + 0xE) = dst[2];
    }
    func_80015978((s32)(obj + 4), (s32 *)src);
    src[3] = 0;
    func_8014C4AC((s32)obj, 0x1C, 0, src,
                  *(s16 *)(*(u8 **)(self + 0x20) + 0x12));
    *(s32 *)(self + 0x18C) = 0;
}
