/* SC02.CD FILE_031 / ov_SC02_031 retail span [801567BC,80156848).
 * Offset 0x2E664 at overlay base 80128158. SHA256(span)=e28d8092d0bb074dabc3c1effa7aff62320fc6b27ff9ffff14ac94e84e2d6985.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801567bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801567BC - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern u8 D_8011DAD8[];
extern s32 D_801151E0[];
extern s32 func_8014C568(s16 *a0, s16 *a1);

void func_801567BC(s32 a0) {
    s32 obj = a0;
    s32 i = 0;
    u8 *q = D_8011DAD8;
    s32 *p = D_801151E0;
    do {
        if (*p & 1) {
            *(s16 *)(*(s32 *)(obj + 0x20) + 0x12) =
                ((s32 (*)(void *, void *))func_8014C568)((void *)obj, q);
        }
        q += 8;
        i += 1;
        p += 1;
    } while ((u32)i < 3);
}
