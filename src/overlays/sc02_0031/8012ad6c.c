/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012AD6C,8012AD80).
 * Offset 0x2C14 at overlay base 80128158. SHA256(span)=e57477b0c4b76fea2c1197fc7b33bc2f7ae50a824ab17f3899da7aecd46c214f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ad6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012AD6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012AD6C(void *a0) {
    *(short *)((char *)a0 + 0x34) = *(unsigned short *)((char *)a0 + 0x34) + 1;
}
