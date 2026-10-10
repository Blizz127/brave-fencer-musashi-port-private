/* SC02 resident retail span [8016FC90,8016FCCC). Offset 0x47B38 at base 80128158.
 * SHA256(span)=fd59a6e221c6127ce358d0d71edd82d257d3dcdb1e4dd144fa663c84ada5401c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181814->D_80188104.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FC90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188104[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016FC90(void *a0) {
    D_80188104[*(u8 *)((s32)a0 + 0x216)](a0);
}
