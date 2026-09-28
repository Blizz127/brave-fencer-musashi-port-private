/* SC02.CD FILE_031 / ov_SC02_031 retail span [801615C4,8016163C).
 * Offset 0x3946C at overlay base 80128158. SHA256(span)=8f62fce154e0aaf783ae242ec538b27044e6bc3cd8419ab2b8c400c4f06d36ef.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801615c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801615C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014ED28();
extern void func_80146D90(s32 a0);
extern void func_8014CC28(s32 a0);
extern void func_8014FA04(s32 a0);

s32 func_801615C4(void * arg0, s32 arg1)
{
    u32 acc;
    acc = 0;
    if (((arg1 & 1) == 0) && (((s32 (*)(void))func_8014ED28)() != 0)) {
        func_80146D90(arg0);
    }
    if (*(s32 *)((u8 *)arg0 + 0x34) > 0) {
        acc |= ((s32 (*)(s32))func_8014CC28)(arg0);
    }
    return acc | ((s32 (*)(s32))func_8014FA04)(arg0);
}
