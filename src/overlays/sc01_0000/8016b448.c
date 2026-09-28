/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B448 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_8014C050(s32 a0, s32 a1);
extern void func_8016B984(void *a0);
extern s32 D_80126B58;
extern void func_8012A568(void (*a0)(void));

s32 func_8016B448(s32 arg0, s32 arg1)
{
    s32 temp_v0;
    temp_v0 = func_8014C050(&D_80126B58, 0x1E);
    if (temp_v0 != 0) {
        func_8016B984(temp_v0);
    }
    func_80146A6C(0x1E, arg0, M2C_FIELD(arg0, s16 *, 0x7C), M2C_FIELD(arg0, s16 *, 0x7E), (s32) M2C_FIELD(arg0, s16 *, 0x80), arg1, 0);
}
