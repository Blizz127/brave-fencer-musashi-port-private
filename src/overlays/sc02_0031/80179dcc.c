/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179DCC,80179DF8).
 * Offset 0x51C74 at overlay base 80128158. SHA256(span)=4ffe3df98bb346978f2fd38d1336f21ca6a79a867fc85d4e1419f93c46ef316b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179dcc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179DCC - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80179DCC(short a0) {
    short sp10[2];
    sp10[1] = a0;
    sp10[0] = 2;
    func_80179B74(sp10);
}
