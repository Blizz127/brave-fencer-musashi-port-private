/* SC02.CD FILE_031 / ov_SC02_031 retail span [801542A4,801542DC).
 * Offset 0x2C14C at overlay base 80128158. SHA256(span)=719b4c092133ab701a9255ebc9fe71183302747d6be050070be7f866dd1453c1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801542a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801542A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154418(void *a0);

void func_801542A4(s32 *a0, s32 a1) {
        *(s32 *)((u8 *)a0 + 0xB4) = a1;
        *(s16 *)((u8 *)a0 + 0xBA) = 1;
        *(s16 *)((u8 *)a0 + 0xB8) = 1;
        *(s8 *)((u8 *)a0 + 0xBC) = 0;
        *(s8 *)((u8 *)a0 + 0xBD) = 0;
        *(s8 *)((u8 *)a0 + 0xDC) = 0;
        ((void (*)(void))func_80154418)();
    }
