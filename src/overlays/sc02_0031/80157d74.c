/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157D74,80157DC4).
 * Offset 0x2FC1C at overlay base 80128158. SHA256(span)=2f828a1a72fe75d1fd601033659c01c964f0890366f5962fbfd130e43561dfca.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157d74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157D74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80157DC4(void *a0);
extern void func_80157FC4(void *a0);

void func_80157D74(u16 *a0) {
    switch (a0[0]) {
    case 0x24:
        func_80157DC4(a0);
        break;
    case 0x25:
        func_80157FC4(a0);
        break;
    }
}
