/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DA90,8015DAC4).
 * Offset 0x35938 at overlay base 80128158. SHA256(span)=5ac3ef6448edcbd5e48b511d0ebdb8b3237c021b81bc61cfd794746c56888bec.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015da90.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DA90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015DB6C(s32 a0);

void func_8015DA90(s32 *a0) {
    func_80147078(a0, 0xE);
    func_8015DB6C(a0);
}
