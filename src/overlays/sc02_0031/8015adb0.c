/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015ADB0,8015AE2C).
 * Offset 0x32C58 at overlay base 80128158. SHA256(span)=0a110a97958b630a17ea053311b01209cd3fe015a15f794a1e71d5ce20feac6e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015adb0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015ADB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015ADB0(s32 arg0) {
    extern s32 D_8011F730;
    extern void func_80161124(void *a0);
    extern void func_801477E8(s32 *a0, s32 a1);
    extern void func_8014C010(s32 a0, s32 a1);
    extern void func_80146CA0(void *a0);
    if (*(u8 *)(arg0 + 0xA8) >= 0x19) {
        *(u8 *)(arg0 + 0xA8) = 0x18;
    }
    func_80161124(arg0);
    ((void (*)(s32, s32))func_801477E8)(arg0, 0xFFEE0000);
    func_8014C010(arg0, 2);
    D_8011F730 |= 1;
    ((void (*)(s32))func_80146CA0)(arg0);
}
