/* SC02 resident retail span [80142A10,80142A80). Offset 0x1A8B8 at base 80128158.
 * SHA256(span)=98ea06f3e8034aff057074c2cafa499f8b2d5d49da87cf0dda6222cab74248b3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FA7C->D_8018636C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142A10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801270C0;
extern void func_80142A80(void);

void func_80142A10(int param_1)
{

    extern void (*D_8018636C[])();
    if (*(s16 *)&D_801270C0 != 3) {
        D_8018636C[*(u16 *)(param_1 + 2)]();
        if (*(s16 *)(param_1 + 0xFC) != 0) {
            ((void (*)(int))func_80142A80)(param_1);
        }
    }
}
