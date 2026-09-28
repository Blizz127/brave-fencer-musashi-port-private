/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015369C,801536DC).
 * Offset 0x2B544 at overlay base 80128158. SHA256(span)=75b5105e205aa9d49e2ddff5ec15f0418db0e520405a484910aee493b2cd0f69.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015369c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015369C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8011DB28)(s32 a0);

void func_8015369C(s32 a0) {
    if (D_8011DB28 != 0) {
        D_8011DB28(a0 + 0xA0);
    }
    *(u8 *)(a0 + 0xDE) = 0x5A;
}
