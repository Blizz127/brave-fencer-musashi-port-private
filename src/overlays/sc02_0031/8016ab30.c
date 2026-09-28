/* SC02 resident retail span [8016AB30,8016AB6C). Offset 0x429D8 at base 80128158.
 * SHA256(span)=453245d0075b42aac783ed933134666e82b67787299f42539d56339d2b1c208b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801814EC->D_80187DDC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016AB30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187DDC[])(void);

void func_8016AB30(void *a0) {
    D_80187DDC[*(u16 *)((s32)a0 + 0x2)]();
}
