/* SC02 resident retail span [8017BC38,8017BCA0). Offset 0x53AE0 at base 80128158.
 * SHA256(span)=7325fca391814e8ad5e6d50a47991861bbc5b2ec9d7bd50c0d144849a8baadac.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185394->D_801B754C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BC38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801B754C[10])(int);

void func_8017BC38(int param_1)
{
    register int i __asm__("$17");
    register void (**p)(int) __asm__("$16");

    i = 0;
    p = D_801B754C;
    do {
        if (*p != (void (*)(int))0) {
            (*p)(param_1);
        }
        i = i + 1;
        p = p + 1;
    } while (i < 10);
    return;
}
