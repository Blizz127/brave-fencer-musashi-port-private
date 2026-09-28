/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179E1C,80179E48).
 * Offset 0x51CC4 at overlay base 80128158. SHA256(span)=34175c8d7510a9929d592b1abc894a7dc761350adfc5335594e364e2d4bda09c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179e1c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179E1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80179B74(u16 *p);

void func_80179E1C(short a0) {
    short sp10[2];
    sp10[1] = a0;
    sp10[0] = 3;
    func_80179B74(sp10);
}
