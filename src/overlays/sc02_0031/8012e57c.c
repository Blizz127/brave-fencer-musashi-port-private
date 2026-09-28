/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E57C,8012E5CC).
 * Offset 0x6424 at overlay base 80128158. SHA256(span)=41513a26a5445cb70661f9b5804b66e3d450704121cf2122b5a302cadb9baf6c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e57c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E57C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];

s32 func_8012E57C(s32 a0, s32 a1) {
    u8 *p = D_801202A0;
    u8 *end = D_801202A0 + 0x6480;
    if (p != end) {
        s32 key = (s16)a1;
        do {
            if (*(u16 *)(p + 0x0) == a0) {
                if (*(s16 *)(p + 0x70) == key) {
                    return (s32)p;
                }
            }
            p += 0x10C;
        } while (p != end);
    }
    return 0;
}
