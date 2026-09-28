/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139914,80139954).
 * Offset 0x117BC at overlay base 80128158. SHA256(span)=5ccd35eb71ac29e394c26e5f97e6c5879adb3e1cb55b1d1a6ad668ad7894ad82.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139914.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139914 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A8B0(s32 *a0);

void func_80139914(s32 arg0)
{
    s32 temp_a0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    if (M2C_FIELD(arg0, u16 *, 0x18) != 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x40);
        if (temp_a0 != 0) {
            func_8013A8B0(temp_a0);
        }
    }
}
