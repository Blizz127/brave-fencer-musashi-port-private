/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B744,8012B77C).
 * Offset 0x35EC at overlay base 80128158. SHA256(span)=66c200460f09ae886a3758d63a79e1d5251379a837b8ea71055535740707708b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b744.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);

s32 func_8012B744(void *a0, void *a1) {
    s32 ang;
    ang = func_8004CFEC(*(s16 *)((s32)a0 + 0xA) - *(s16 *)((s32)a1 + 0x4),
                 *(s16 *)((s32)a1 + 0x0) - *(s16 *)((s32)a0 + 0x2));
    return (ang - 0x400) & 0xFFF;
}
