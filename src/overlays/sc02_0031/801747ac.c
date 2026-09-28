/* SC02.CD FILE_031 / ov_SC02_031 retail span [801747AC,801747CC).
 * Offset 0x4C654 at overlay base 80128158. SHA256(span)=86e914590783f93d2cae334bc60df976843daf030b0bc55c11487176b44160b5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801747ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801747AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8016F0AC();

s32 func_801747AC(s32 a0) {
    return func_8016F0AC(a0);
}
