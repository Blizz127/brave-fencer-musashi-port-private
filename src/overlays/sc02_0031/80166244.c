/* SC02.CD FILE_031 / ov_SC02_031 retail span [80166244,8016629C).
 * Offset 0x3E0EC at overlay base 80128158. SHA256(span)=1c5f1abf69e9df6a51bc82b68ebbb790770d1f78a4dbc3836442222b5cb3eadc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80166244.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80166244 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80166244(void* arg0) {
    ((void (*)(s32, void*, s16, s16, s16, u32, u32))func_80146A6C)(3, arg0, *(s16*)((u8*)arg0 + 6), *(u16*)((u8*)arg0 + 0xA) - 0x10, *(s16*)((u8*)arg0 + 0xE), 0x8F8FFF8, 0xE000B000);
}
