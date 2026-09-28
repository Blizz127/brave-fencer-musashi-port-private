/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E688,8016E6E4).
 * Offset 0x46530 at overlay base 80128158. SHA256(span)=ef2ac4cdbfcd283e9d2bd04f579791cf5d1bfc476064a6447ff728cf8e2eac5d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e688.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E688 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E778();
extern void func_8012A568(void (*a0)(void));

void func_8016E688(void *a0) {
    u16 *p = (u16 *)a0;
    s16 v;
    p[0x10/2] += 0x200;
    v = p[0x12/2] + p[0x10/2];
    p[0x12/2] = v;
    if (v >= 0x3000) {
        *(s32 *)((u8 *)a0 + 0x1C) = 4;
        *(s16 *)((u8 *)a0 + 0x2) += 1;
    }
    func_8016E778();
}
