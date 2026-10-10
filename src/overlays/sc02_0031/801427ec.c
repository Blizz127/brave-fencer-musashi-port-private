/* SC02 resident retail span [801427EC,80142838). Offset 0x1A694 at base 80128158.
 * SHA256(span)=6717ec6e608040b428905e08fb508186ea774759fdde4f46150b577ced4b46d0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F7C8->D_801860B8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801427EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801270C0;
extern void (*D_801860B8[])(int);

void func_801427EC(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_801860B8[*(u16 *)(param_1 + 2)](param_1);
    }
}
