/* SC02 resident retail span [8016FA84,8016FAC0). Offset 0x4792C at base 80128158.
 * SHA256(span)=29ba1a91945eb728e34b98a3b6d3d8afc7b13c822415832de0ac655d77505d92.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817FC->D_801880EC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FA84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880EC[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016FA84(void *a0) {
    D_801880EC[*(u8 *)((s32)a0 + 0x216)]();
}
