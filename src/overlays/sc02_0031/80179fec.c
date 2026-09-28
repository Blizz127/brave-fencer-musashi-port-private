/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179FEC,8017A040).
 * Offset 0x51E94 at overlay base 80128158. SHA256(span)=0623e227bf666a34800636dbbe0c05b229846524bdb5ce87460e68dde58266bd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179fec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179FEC - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80179FEC(u16 *a0) {
    s16 sp[5];
    sp[0] = 0x20;
    sp[1] = a0[0];
    sp[2] = a0[1];
    sp[3] = a0[2];
    sp[4] = a0[3];
    func_80179B74(sp);
}
