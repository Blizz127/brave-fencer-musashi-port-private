/* SC02 resident retail span [8017A144,8017A180). Offset 0x51FEC at base 80128158.
 * SHA256(span)=424027e85f83dcefe2628edce21c40875555ecc7016c3f80a91a9c5c7096d165.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018538C->D_801B7544.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A144 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_801B7544;
extern void func_80179B74(u16 *p);

void func_8017A144(s32 a0) {
    s16 sp10;
    sp10 = 0x1B;
    func_80179B74(&sp10);
    D_801B7544 = a0;
}
