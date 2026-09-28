/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FCCC,8016FD08).
 * Offset 0x47B74 at overlay base 80128158. SHA256(span)=8c5980139236178591e06b78151a84d016baaa479d6cdc3ab7b6ae2237689774.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fccc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FCCC - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8016FD08(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FCCC(u8 *a0) {
    func_801719A4((int)a0, 1);
    func_80171990(a0);
    func_8016FD08(a0);
}
