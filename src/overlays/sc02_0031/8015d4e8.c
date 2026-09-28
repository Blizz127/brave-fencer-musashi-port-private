/* SC02 resident retail span [8015D4E8,8015D524). Offset 0x35390 at base 80128158.
 * SHA256(span)=1ab8cdcf5d6bcdcf29599d9aba32481eedc186b8ed57308f149750419e7ccdbf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180C54->D_80187544.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D4E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8015D4E8(s16 *a0) {

    extern void (*D_80187544[])(void);
    D_80187544[*(u16 *)((s32)a0 + 0x2)]();
}
