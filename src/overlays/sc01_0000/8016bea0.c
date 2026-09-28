/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BEA0 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_80146C3C();
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_801A4B1C;
extern M2C_UNK D_801A4B20;
extern void func_8012A568(void (*a0)(void));

s32 func_8016BEA0(s32 param_1)
{
    extern void func_8016BF50(void);

    int iVar2;
    unsigned short uVar1;

    iVar2 = *(int *)(((int)param_1) + 0x20);
    func_8016BF50();
    uVar1 = *(unsigned short *)(((int)param_1) + 0x10) - 0x18;
    *(unsigned short *)(((int)param_1) + 0x10) = uVar1;
    *(unsigned short *)(iVar2 + 0x1a) = *(unsigned short *)(iVar2 + 0x1a) + uVar1;
    *(unsigned short *)(iVar2 + 0x12) = (*(unsigned short *)(iVar2 + 0x12) + 0x22) & 0xfff;
    ((void (*)(int, void *, void *, int))func_8016BFA8)(((int)param_1), &(*(int *)&D_801A4B1C), &(*(int *)&D_801A4B20), iVar2 + 0x18);
    if (*(short *)(iVar2 + 0x1a) < 0) {
        ((void (*)(int))func_80146C3C)(((int)param_1));
    }
}
