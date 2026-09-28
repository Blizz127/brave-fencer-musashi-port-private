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
extern s16 D_801A5704;
extern s16 D_801A5706;
extern s16 D_801A5708;
extern s16 D_801A570C;
extern s16 D_801A570E;
extern s16 D_801A5710;

void func_8017B824(void) {
    D_801A5704 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x48);
    D_801A5706 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x4C);
    D_801A5708 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x50);
    D_801A570C = (s16) M2C_FIELD(D_801151D4, s32 *, 0x3C);
    D_801A570E = (s16) M2C_FIELD(D_801151D4, s32 *, 0x40);
    D_801A5710 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x44);
}
