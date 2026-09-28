/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017331C,8017334C).
 * Offset 0x4B1C4 at overlay base 80128158. SHA256(span)=e5c48f06b7703d2fbb0c65858ab31eecce9387cee1dd70da613c5549470c8b38.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017331c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017331C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016F2C8(void);
extern s32 func_80174650(s32);

void func_8017331C(s32 *a0) {
        ((void (*)(s32 *))func_8016F2C8)(a0);
        func_80174650((s32)a0);
    }
