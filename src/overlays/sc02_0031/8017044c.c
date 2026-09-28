/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017044C,801704B0).
 * Offset 0x482F4 at overlay base 80128158. SHA256(span)=4302a56210c5335dbe70fab4bf4be581f2d83c4be3585bdbad5250280390d224.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017044c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017044C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151D4;
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8017044C(u8 * a0)
{
    s16 buf[3];
    s32 *p;
    p = (s32 *)D_801151D4;
    buf[0] = (s16)p[0xF];   /* 0x3C */
    buf[1] = (s16)p[0x10];  /* 0x40 */
    buf[2] = (s16)p[0x11];  /* 0x44 */
    if (func_80171AB0(a0, buf) == 0) {
        func_80171928((void *)a0);
    }
}
