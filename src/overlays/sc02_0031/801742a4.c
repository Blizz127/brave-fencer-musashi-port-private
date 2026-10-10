/* SC02 resident retail span [801742A4,801742E0). Offset 0x4C14C at base 80128158.
 * SHA256(span)=e2a7f309d820a4d88e1f16097b40a9468783eb943cbc5f1026b24eb6c7db5346.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819C0->D_801882B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801742A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801742A4(void *a0) {

    extern void (*D_801882B0[])(void *);
    D_801882B0[*(u8 *)((s32)a0 + 0x214)](a0);
}
