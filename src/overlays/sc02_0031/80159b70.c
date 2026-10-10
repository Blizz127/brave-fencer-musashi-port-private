/* SC02 resident retail span [80159B70,80159BAC). Offset 0x31A18 at base 80128158.
 * SHA256(span)=e7599dccb457339ce749ebaecf03fe3473dbfc018e3ee3823e59d0be0f0fbb40.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B64->D_80187454.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159B70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187454[])(void *);

void func_80159B70(void *a0) {
    D_80187454[*(u16 *)((s32)a0 + 0x2)](a0);
}
