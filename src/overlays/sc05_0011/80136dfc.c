/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80136DFC - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 *D_80126B78;
extern u16 D_80126CC4;
extern M2C_UNK func_800153CC(M2C_UNK, u16, M2C_UNK, M2C_UNK, s32, s32);

void func_80136DFC(void) {
    ((void (*)(s32, s32, s32, s32, s32, s32))func_800153CC)(0xA, (*(s16 *)&D_80126B5E), 0x110, 0x3C, 4, 0);
    ((void (*)(s32, s32, s32, s32, s32, s32))func_800153CC)(0xB, (*(s16 *)&D_80126B62), 0x110, 0x44, 4, 0);
    ((void (*)(s32, s32, s32, s32, s32, s32))func_800153CC)(0xC, (*(s16 *)&D_80126B66), 0x110, 0x4C, 4, 0);
    ((void (*)(s32, s32, s32, s32, s32, s32))func_800153CC)(0xD, *(s16 *)((s32)D_80126B78 + 0x12), 0x110, 0x54, 4, 0);
    ((void (*)(s32, s32, s32, s32, s32, s32))func_800153CC)(0xE, D_80126CC4, 0x110, 0x5C, 4, 0);
}
