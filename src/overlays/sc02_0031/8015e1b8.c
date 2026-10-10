/* SC02 resident retail span [8015E1B8,8015E1F4). Offset 0x36060 at base 80128158.
 * SHA256(span)=144ab3ed32c971b2bca68654f52f75b8a6fe8ac1e591dd6dea4a277962940ebb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180CD4->D_801875C4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E1B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8015E1B8(s32 a0) {

    extern void (*D_801875C4[])(s32);
    D_801875C4[*(u16 *)((s32)a0 + 0x2)](a0);
}
