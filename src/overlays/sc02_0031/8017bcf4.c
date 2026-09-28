/* SC02 resident retail span [8017BCF4,8017BD50). Offset 0x53B9C at base 80128158.
 * SHA256(span)=e14d8d2d36f57ed004d379144c69b9c0a7ea3a32a792a1141cd99dc628b3a7a2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_80185C08->D_801B7A98.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BCF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_801B7504;
extern s16 D_801B7A98;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);

void func_8017BCF4(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801B7504 = D_801B7504 + 1;
    if (0x18 < D_801B7504) {
        func_8012A4BC();
        D_801B7A98 = 0;
    }
    return;
}
