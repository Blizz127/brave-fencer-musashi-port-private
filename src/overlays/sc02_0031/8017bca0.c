/* SC02 resident retail span [8017BCA0,8017BCF4). Offset 0x53B48 at base 80128158.
 * SHA256(span)=2a352d71daf9fd4605cc90ab3b731b5187ce888d742b19e8e35dcb519aaf5f66.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_80185C08->D_801B7A98.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BCA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017B0E4(int, int);
extern s16 D_801B7504;
extern s16 D_801B7A98;

void func_8017BCA0(int param_1) {
    func_8017B0E4(param_1, 0xC);
    D_801B7504 = D_801B7504 + 1;
    if (D_801B7504 >= 0x1F) {
        D_801B7A98 = 2;
    }
}
