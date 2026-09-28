/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017115C,8017118C).
 * Offset 0x49004 at overlay base 80128158. SHA256(span)=b0e35f1687ef926785b50d8da8b47614683298071f7b5db7d817dc4b27fb3a57.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017115c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017115C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171990(u8 *a0);
extern void func_8017118C(u8 *a0);

void func_8017115C(u8 *a0) {
    func_80171990(a0);
    func_8017118C(a0);
}
