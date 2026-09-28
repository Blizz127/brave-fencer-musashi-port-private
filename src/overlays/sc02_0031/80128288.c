/* SC02 resident retail span [80128288,801282CC). Offset 0x130 at base 80128158.
 * SHA256(span)=6d7c4dd20813e292c7011e14f7eb59e1d6172ece4f3a4da047728bbd627805af.
 * Words are the guest's own loaded image (artifacts/sc02-resident-20260910),
 * not the sc01-title-code capture: that capture is a different member and
 * makes the port refuse at 801282AC. C is the member-0012 shape with the
 * dispatch table at this member's D_80184F08; oracle MATCH 17/17.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128288 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_800B99F6;
extern void (*D_80184F08[])(void);

void func_80128288(void) {
    u32 v1;
    v1 = D_800B99F6;
    if (v1 < 9) {
        D_80184F08[v1]();
    }
}
