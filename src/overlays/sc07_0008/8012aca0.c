/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012ACA0 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_8012AAAC();
extern M2C_UNK D_8017D62C;

void func_8012ACA0(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x90) = &D_8017D62C;
    M2C_FIELD(arg0, s32 *, 0x94) = 0;
    M2C_FIELD(arg0, s32 *, 0x9C) = 0;
    M2C_FIELD(arg0, s16 *, 0x9A) = 0;
    M2C_FIELD(arg0, u16 *, 0x72) = (u16) (M2C_FIELD(arg0, u16 *, 0x72) & 0xF9FF);
    ((void (*)(void))func_8012AAAC)();
}
