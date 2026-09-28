/* SC02.CD FILE_031 / ov_SC02_031 retail span [801632F0,80163328).
 * Offset 0x3B198 at overlay base 80128158. SHA256(span)=151762e577c6c31e070a429f38fbc5cf49431a95b93b31f12d92069225654e6a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801632f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801632F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80115200;

s32 func_801632F0(void) {
    s32 i = 0;
    s32 *p = &D_80115200;
    s32 v0;
    do {
        v0 = p[0];
        if (v0 != 0) {
            return v0;
        }
        i++;
        p++;
    } while (i < 3);
    return 0;
}
