/* SC02.CD FILE_031 / ov_SC02_031 retail span [801706E8,80170718).
 * Offset 0x48590 at overlay base 80128158. SHA256(span)=07b1905e832db9d12ec8ccf6418076b188b6dec310210fbab7222f7a1835633e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801706e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801706E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171990(u8 *a0);
extern void func_80170718(void *a0);

void func_801706E8(u8 *a0) {
    func_80171990(a0);
    func_80170718(a0);
}
