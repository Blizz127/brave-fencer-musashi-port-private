/* SC02.CD FILE_031 / ov_SC02_031 retail span [801598BC,801598E0).
 * Offset 0x31764 at overlay base 80128158. SHA256(span)=c32052f384fdfbe837f759d580e00d34f7b158a3b9b771e2d2d5f61348e2a9ae.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801598bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801598BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_800167F0(int arg);

int func_801598BC(void) {
    return (func_800167F0(4) & 0xFFFF) != 0;
}
