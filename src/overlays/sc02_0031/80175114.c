/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175114,80175150).
 * Offset 0x4CFBC at overlay base 80128158. SHA256(span)=f8efb19c2f015b8b89b3983e33c6192686f21223cdbc74f0e4b6febe89a92f66.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175114.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175114 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80175184(s32 *a0);

void func_80175114(s32 *a0) {
    func_80147078(a0, 8);
    *(s16 *)((s32)a0 + 2) = 1;
    func_80175184(a0);
}
