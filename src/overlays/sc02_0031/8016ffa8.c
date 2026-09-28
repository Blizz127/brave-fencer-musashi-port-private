/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FFA8,8016FFDC).
 * Offset 0x47E50 at overlay base 80128158. SHA256(span)=0bec840820af0376980dd8cc4bc8787b3fcb106766df88982f2da553fd66e510.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016ffa8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80171990(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FFA8(u8 *a0) {
    *(u16 *)(a0 + 0xAC) |= 0x40;
    *(u16 *)(a0 + 0xAA) |= 0x40;
    func_80171990(a0);
}
