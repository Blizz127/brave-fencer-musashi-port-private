/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012AD80,8012ADE4).
 * Offset 0x2C28 at overlay base 80128158. SHA256(span)=c2ac1419d02439af5611104dd8310dedcc7ac3da87f9782a26d191741c52c55d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ad80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012AD80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012AD80(s32 a0) {
    *(s32*)(a0 + 0x10) += *(s32*)(a0 + 0x44);
    *(s32*)(a0 + 0x14) += *(s32*)(a0 + 0x48);
    *(s32*)(a0 + 0x18) += *(s32*)(a0 + 0x4C);
    *(s32*)(a0 + 0x4) += *(s32*)(a0 + 0x10);
    *(s32*)(a0 + 0x8) += *(s32*)(a0 + 0x14);
    *(s32*)(a0 + 0xC) += *(s32*)(a0 + 0x18);
}
