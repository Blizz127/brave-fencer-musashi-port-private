/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017197C,80171990).
 * Offset 0x49824 at overlay base 80128158. SHA256(span)=644201adf9e62ea5c692e8b48283d884789be91789b01e92f76fab9ca3dbb982.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017197c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017197C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_8017197C(u8 *a0)
{
    s32 v = a0[0x215] + 1;
    a0[0x216] = 0;
    a0[0x215] = v;
    return v;
}
