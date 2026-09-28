/* SC02 resident retail span [80128CFC,80128D60). Offset 0xBA4 at base 80128158.
 * SHA256(span)=8a5b054c63fefe682e5477020e9242fedf682c22f4c1a71f261810fa155b1773.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E640->D_80184F30; D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128CFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
extern s32 D_801B5128;
extern CdFileLoc D_800AE830[];
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);

s32 func_80128CFC(s32 arg0) {

    extern s16 D_80184F30[];
    s16 idx = D_80184F30[arg0];

    if (idx >= 0) {
        func_8001ABBC(0, 0, (u8 *)&D_800AE830[idx], D_801B5128, 0);
    } else {
        return 1;
    }
}
