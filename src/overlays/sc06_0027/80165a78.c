/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165A78 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_80165AC8(void);

void func_80165A78(s32 arg0)
{
    void *temp_a0;
    func_80165AC8();
    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(arg0, s8 *, 0x197) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) & ~8);
    M2C_FIELD(temp_a0, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x2C) & 0xFFDF);
}
