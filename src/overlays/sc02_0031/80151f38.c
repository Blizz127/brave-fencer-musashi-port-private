/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151F38,80151FB4).
 * Offset 0x29DE0 at overlay base 80128158. SHA256(span)=b65a3ec89e629583f5354bfb6bcd643fda8248d0cf8ec26aaea71f596e7ec204.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151f38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151F38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80151FB4(s32 a0);
extern void func_80159B3C(void *a0);
extern void func_80165718(s32 a0);
extern s32 func_80172630(u8 *a0);

void func_80151F38(s32 *a0) {
    func_80149020(a0);
    *(s16 *)((char *)a0 + 0x64) = *(u16 *)((char *)a0 + 0x64) - (*(u8 *)((char *)a0 + 0xDE) << 6);
    *(u8 *)((char *)a0 + 0xDE) = *(u8 *)((char *)a0 + 0xDE) + 8;
    if (*(s16 *)((char *)a0 + 0x64) < 0x1000) {
        func_80151FB4((s32)a0);
        func_80159B3C(a0);
        func_80165718((s32)a0);
    } else {
        func_80172630((u8 *)a0);
    }
}
