/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B824 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern s32 D_801151D4;
extern s16 D_801B7594;
extern s16 D_801B7596;
extern s16 D_801B7598;
extern s16 D_801B759C;
extern s16 D_801B759E;
extern s16 D_801B75A0;

void func_8017B824(void) {
    D_801B7594 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x48);
    D_801B7596 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x4C);
    D_801B7598 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x50);
    D_801B759C = (s16) M2C_FIELD(D_801151D4, s32 *, 0x3C);
    D_801B759E = (s16) M2C_FIELD(D_801151D4, s32 *, 0x40);
    D_801B75A0 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x44);
}
