/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017250C,80172560).
 * Offset 0x4A3B4 at overlay base 80128158. SHA256(span)=4d4b13bfed885aa01ecf9f09fdbad531e98f2f25ae914ca169296f287b5de9aa.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017250c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017250C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80172560(u8 *a0, u8 *a1);

int func_8017250C(short *a0, short *a1) {
    if (func_80172560(a0, a1) == 0) {
        return 0;
    }
    a0[3] = a1[0];   /* sh v0,6(s1) <- lhu 0(s0) */
    a0[7] = a1[2];   /* sh v1,0xE(s1) <- lhu 4(s0) */
    return 1;
}
