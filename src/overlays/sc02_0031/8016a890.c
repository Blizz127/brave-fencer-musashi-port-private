/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016A890,8016A8FC).
 * Offset 0x42738 at overlay base 80128158. SHA256(span)=5be8f26a04f2940d27fdb91b657b63258693b19f4069a862e6be6133806d5f14.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016a890.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A890 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016A8FC(s32 a0);
extern void func_80146C3C();

void func_8016A890(s32 arg0)
{
    s16 *p = *(s16 **)((u8 *)arg0 + 0x34);
    if (*(s32 *)((u8 *)arg0 + 0x1C) < 4 && *(u16 *)p == 0x14) {
        ((void (*)(void))func_8016A8FC)();
        *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 0x1C) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(arg0);
    }
}
