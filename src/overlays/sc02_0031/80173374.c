/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173374,801733A4).
 * Offset 0x4B21C at overlay base 80128158. SHA256(span)=911ee0da7d976b09c7448c874841828b395d58a1fe55ac5e64c3764eb06d71c7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173374.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016F2EC(void);
extern s32 func_80174650(s32);

void func_80173374(s32 *a0) {
        ((void (*)(s32 *))func_8016F2EC)(a0);
        func_80174650((s32)a0);
    }
