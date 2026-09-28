/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F214,8012F274).
 * Offset 0x70BC at overlay base 80128158. SHA256(span)=d540c6a437ee2771b23a3b8980f74b631ad2af0e5c8471216a64ce35db20a952.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f214.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F214 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);

void func_8012F214(s32 a0, s32 a1, s32 a2) {
    s32 *p = (s32 *)(*(s32 *)(a0 + 0x20) + 0x34);
    s32 buf[2];
    func_8004914C(p);
    func_800491AC(p);
    func_8004945C(a1, a2, buf);
}
