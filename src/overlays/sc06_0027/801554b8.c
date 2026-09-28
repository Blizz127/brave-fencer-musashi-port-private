/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801554B8 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern s32 func_801659DC();

s32 func_801554B8(void *arg0) {
    s32 var_v0;
    u8 temp_a0;
    temp_a0 = M2C_FIELD(arg0, u8 *, 0x1A0);
    var_v0 = 0;
    if (temp_a0 != M2C_FIELD(arg0, u8 *, 0x196)) {
        if (func_800D02D0(temp_a0) != 0) {
            M2C_FIELD(arg0, u8 *, 0x196) = (u8) M2C_FIELD(arg0, u8 *, 0x1A0);
            func_801659DC(arg0);
            return 0;
        }
        var_v0 = 1;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
