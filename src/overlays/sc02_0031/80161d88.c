/* SC02 resident retail span [80161D88,80161E08). Offset 0x39C30 at base 80128158.
 * SHA256(span)=bbab2aa72f8250fd30f6d01dc1ad45ccfe8407c654276a6fca58079ec7947653.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180EBC->D_801877AC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161D88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800AE6B0;
extern s32 D_800AE6A8;
extern s32 func_80029178(s32 arg);
extern void func_80029124(s32, s32);
extern void func_800D1734(void *);
extern s32 D_801877AC;

void func_80161D88(void) {
    if ((D_800AE6B0 & 0x80FFFFFF) == 0 && (D_800AE6A8 & 0x80FFFFFF) == 0 &&
        (func_80029178(0x141) & 0xFF) != 0) {
        func_80029124(0x141, 0);
        func_80029124(0x95, 1);
        func_800D1734(&D_801877AC);
    }
}
