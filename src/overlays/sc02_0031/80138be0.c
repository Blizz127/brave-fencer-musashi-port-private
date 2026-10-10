/* SC02 resident retail span [80138BE0,80138C30). Offset 0x10A88 at base 80128158.
 * SHA256(span)=6cfd046113b4190098db3f315bc54e4009a2ddda3f28d69b417756f063df7305.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E984->D_80185274.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80185274[])(int);

void func_80138BE0(int p)
{
    if (*(unsigned short *)(p + 0xe) != 0) {
        *(unsigned short *)(p + 0xe) -= 1;
    }
    D_80185274[*(short *)(p + 4)](p);
}
