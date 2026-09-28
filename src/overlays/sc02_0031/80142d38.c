/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142D38,80142DB8).
 * Offset 0x1ABE0 at overlay base 80128158. SHA256(span)=43e36762f4bbc51df4616874efd0f6a328bf8bfbfd0138311f28978c5eab5ed2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142d38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142D38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BEE8(s32 a0);

s32 func_80142D38(s32 *a0) {
    if (func_8012BEE8((s32)a0) == 1) {
        return 1;
    }
    if (a0[0x1C / 4] & 1) {
        ((s32 *)a0[0x20 / 4])[1] |= 0x80000000;
    } else {
        ((s32 *)a0[0x20 / 4])[1] &= 0x7FFFFFFF;
    }
    return 0;
}
