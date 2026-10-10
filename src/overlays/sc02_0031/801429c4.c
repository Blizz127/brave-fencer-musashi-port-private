/* SC02 resident retail span [801429C4,80142A10). Offset 0x1A86C at base 80128158.
 * SHA256(span)=55b1e346187496962bba1b22e05d01fa68fbf479f9d72d78e5dc4aff87979d52.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FA6C->D_8018635C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801429C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801270C0;
extern void (*D_8018635C[])(int);

void func_801429C4(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_8018635C[*(u16 *)(param_1 + 2)](param_1);
    }
}
