/* SC02.CD FILE_031 / ov_SC02_031 retail span [801319E0,80131A34).
 * Offset 0x9888 at overlay base 80128158. SHA256(span)=44508efda94b3f706749a92198aecfeaca8e023857b3c59a76bca14c2a7ce29f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801319e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801319E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void *a0);

void func_801319E0(s32 arg0) {
    /* arg0 stays in $s0 (callee-saved) across all three calls -- live across each jal,
     * so clean C allocates it there naturally (no register pin needed). */
    if (((s32 (*)(int, int))func_80131CA8)(arg0, 0x11) == 0) {
        if (*(s32 *)(arg0 + 0x78) != 0) {
            func_8002A04C(arg0);
        }
        func_8012C218((void *)arg0);
    }
}
