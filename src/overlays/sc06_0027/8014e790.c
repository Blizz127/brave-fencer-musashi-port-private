/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014E790 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8014E790(s32 arg0, s16 * arg1, s16 * arg2)
{
    s32 temp_a1;
    void *temp_s0;
    temp_s0 = M2C_FIELD(arg0, void **, 0x180);
    if ((M2C_FIELD(temp_s0, u16 *, 0) == 0) || !(M2C_FIELD(temp_s0, u16 *, 0x5C) & 0x20) || (temp_a1 = M2C_FIELD(temp_s0, s32 *, 0x58), (temp_a1 == 0)) || (func_80135888(M2C_FIELD(temp_s0, s32 *, 0x20), temp_a1, arg1, arg2) == 0)) {
        M2C_FIELD(arg0, void **, 0x180) = NULL;
        return 0;
    }
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(temp_s0, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(temp_s0, u16 *, 0xA);
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(temp_s0, u16 *, 0xE);
    return 1;
}
