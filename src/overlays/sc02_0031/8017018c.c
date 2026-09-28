/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017018C,801701C8).
 * Offset 0x48034 at overlay base 80128158. SHA256(span)=ad40040dbc3dff8ee0cacf04c5c958afaab0fe0c9800beb27618205d3970016f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017018c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017018C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_801701C8(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8017018C(u8 *a0) {
    func_801719A4((int)a0, 1);
    func_80171990(a0);
    func_801701C8(a0);
}
