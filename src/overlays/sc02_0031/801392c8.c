/* SC02.CD FILE_031 / ov_SC02_031 retail span [801392C8,801392FC).
 * Offset 0x11170 at overlay base 80128158. SHA256(span)=0815f425158a92060a765293339cc3693cef7a73853fd6a20477877184ae49a3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801392c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801392C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801395D4(void *);

void func_801392C8(void *a0) {
    func_801395D4(a0);
    *(s8 *)((s32)a0 + 0x1E) = 0;
    *(s16 *)((s32)a0 + 0x4) = 5;
}
