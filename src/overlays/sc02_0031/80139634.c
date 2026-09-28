/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139634,80139680).
 * Offset 0x114DC at overlay base 80128158. SHA256(span)=d434b54cc1a6b562128b1f565ba6b40cfe31910cab9ee3efbaefc4bbc98acec8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139634.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139634 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);

void func_80139634(void *a0) {
    s16 sp[4];
    sp[0] = *(u16 *)((u8 *)a0 + 0x38);
    sp[1] = *(u16 *)((u8 *)a0 + 0x3A);
    sp[2] = 0x38;
    sp[3] = 0x30;
    func_80059888(&sp[0], 0, 0, 0);
}
