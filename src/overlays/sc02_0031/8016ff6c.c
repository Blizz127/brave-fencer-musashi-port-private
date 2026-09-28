/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FF6C,8016FFA8).
 * Offset 0x47E14 at overlay base 80128158. SHA256(span)=e2c0a4ba33d332de1f3d476c6f444b30f3802a469d2e67f451c2a3918cb9d796.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016ff6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FF6C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8016FFA8(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FF6C(u8 *a0) {
    func_801719A4((int)a0, 2);
    func_80171990(a0);
    func_8016FFA8(a0);
}
