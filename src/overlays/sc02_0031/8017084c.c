/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017084C,801708B0).
 * Offset 0x486F4 at overlay base 80128158. SHA256(span)=63343b1d88a5f276ffb74fcdc77b5f1539c9a52ccde6e66f9d1674c870acdff6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017084c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017084C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801719A4(int a0, int a1);
extern void func_8014706C(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_8016BADC(void *a0, s32 a1, s32 a2);
extern s32 func_80171990(u8 *a0);
extern void func_801708B0(void *a0);
extern u8 D_800D5DA8;

void func_8017084C(s32 a0) {
    func_801719A4(a0, 1);
    func_8014706C((void *)a0);
    func_80154274((s32 *)a0, (s32)&D_800D5DA8);
    func_8016BADC((void *)a0, -0x40, 0x40);
    func_80171990((u8 *)a0);
    func_801708B0((void *)a0);
}
