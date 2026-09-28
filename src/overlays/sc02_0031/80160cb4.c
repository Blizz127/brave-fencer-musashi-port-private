/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160CB4,80160D10).
 * Offset 0x38B5C at overlay base 80128158. SHA256(span)=01c3d36dfbf5c70cb366ff25ea256f6bf70ca475e9a4d8037676a8b8f667f5bc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160cb4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160CB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161208();
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_80160CB4(s32 *a0) {
    if (func_80161208() == 0) {
        if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
            func_80154150((s32)a0, 0x27);
            func_80154A74((s32)a0, 0x1F);
            func_80146CA0(a0);
        }
    }
}
