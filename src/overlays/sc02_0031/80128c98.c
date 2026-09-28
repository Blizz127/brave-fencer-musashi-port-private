/* SC02 resident retail span [80128C98,80128CFC). Offset 0xB40 at base 80128158.
 * SHA256(span)=ff4ece4b660a107931bcf4af13a15cd8d656a363d24f91e8389ce3ff00afbf36.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E630->D_80184F20; D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128C98 - byte-exact against retail at -O2 (tools/register_match.py). */
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
typedef CdFileLoc CdFileLoc_80128C98;
extern s32 D_801B5128;
extern CdFileLoc_80128C98 D_800AE830[];
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);

s32 func_80128C98(s32 arg0) {

    extern s16 D_80184F20[];
    s16 idx = D_80184F20[arg0];

    if (idx >= 0) {
        func_8001ABBC(0, 0, (u8 *)&D_800AE830[idx], D_801B5128, 0);
    } else {
        return 1;
    }
}
