/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A7D4,8012A828).
 * Offset 0x267C at overlay base 80128158. SHA256(span)=00a50a76c5d500ff1147ab5963e770514560d73c521cd169967905359688ee59.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a7d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A7D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151D4;

void func_8012A7D4(void *arg0, void *arg1) {
    s32 p;
    p = D_801151D4;
    *(s16 *)((u8 *)arg0 + 0x0) = *(s32 *)(p + 0x3C);
    *(s16 *)((u8 *)arg0 + 0x2) = *(s32 *)(p + 0x40);
    *(s16 *)((u8 *)arg0 + 0x4) = *(s32 *)(p + 0x44);
    *(s16 *)((u8 *)arg1 + 0x0) = *(s32 *)(p + 0x48);
    *(s16 *)((u8 *)arg1 + 0x2) = *(s32 *)(p + 0x4C);
    *(s16 *)((u8 *)arg1 + 0x4) = *(s32 *)(p + 0x50);
}
