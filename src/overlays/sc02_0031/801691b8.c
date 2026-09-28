/* SC02.CD FILE_031 / ov_SC02_031 retail span [801691B8,80169228).
 * Offset 0x41060 at overlay base 80128158. SHA256(span)=9b49efa6992051207a970c67412ad4e26eeb75c7e034389f40de62615cfeee75.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801691b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801691B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80169228(void);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_801691B8(void *a0) {
    if (*(s32 *)((s32)a0 + 0x1C) < 10) {
        func_80169228();
        func_800D22E4((s32)a0);
        *(s32 *)((s32)a0 + 0x14) += 0x10000;
        *(s32 *)((s32)a0 + 0x1C) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)a0);
    }
}
