/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DC84,8015DCB8).
 * Offset 0x35B2C at overlay base 80128158. SHA256(span)=5c5cfdbd07773f8c12d5511ce20cb0d78ad1e9081e37408a35eec025c86f5e48.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015dc84.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DC84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(int, int);
extern int func_8015DD74(int);

int func_8015DC84(int a0) {
    func_80154A74(a0, 0x11);
    return func_8015DD74(a0);
}
