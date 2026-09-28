/* SC02 resident retail span [8017496C,801749A8). Offset 0x4C814 at base 80128158.
 * SHA256(span)=c21e9510ce20642b5cf987eeb39902b24c3e6a3de82f982d4e8f99da89bb6911.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819F4->D_801882E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017496C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_8017496C(void *a0) {

    extern void (*D_801882E4[])(void);
    D_801882E4[*(u8 *)((s32)a0 + 0x4)]();
}
