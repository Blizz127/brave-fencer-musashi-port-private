/* SC02.CD FILE_031 / ov_SC02_031 retail span [801636D0,80163764).
 * Offset 0x3B578 at overlay base 80128158. SHA256(span)=d63a19729e83e0051aa618e9bb95a22c7e086cf1be55059c39ecb8afd62d17d9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801636d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801636D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);
extern u16 D_80126B18[];
extern s32 D_80115200;

void func_801636D0(s32 a0, s32 a1) {
    u32 i;
    s32 v;
    u16 *p;
    s32 *q;
    i = 0;
    v = a1 & 0x7FFF;
    p = D_80126B18;
    q = &D_80115200;
    do {
        if (*q & 1) {
            func_8014AD30(a0, p, 0, v & 0xFFFF);
        }
        p += 4;
        i++;
        q += 1;
    } while (i < 3);
}
