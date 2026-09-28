/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BD78 - byte-exact against retail at -O2 (tools/register_match.py). */
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

extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_8019C6BC;
extern M2C_UNK D_8019C6C0;
extern void func_8012A568(void (*a0)(void));

s32 func_8016BD78(s32 param_1)
{
    extern void func_8016BF50(void);
    extern u8 D_8019C6BD;
    extern u8 D_8019C6BE;
    extern u8 D_8019C6C1;
    extern u8 D_8019C6C2;

    s32 iVar2;
    u16 uVar1;
    u8 *p1;
    u8 *p2;

    iVar2 = *(s32 *)(param_1 + 0x20);
    func_8016BF50();

    p1 = &(*(u8 *)&D_8019C6BC);
    if (*p1 != 0) *p1 -= 4;
    if (D_8019C6BD != 0) D_8019C6BD -= 4;
    if (D_8019C6BE != 0) D_8019C6BE -= 4;
    p2 = &(*(u8 *)&D_8019C6C0);
    if (*p2 != 0) *p2 -= 4;
    if (D_8019C6C1 != 0) D_8019C6C1 -= 4;
    if (D_8019C6C2 != 0) D_8019C6C2 -= 4;

    uVar1 = *(u16 *)(iVar2 + 0x18) - 0x80;
    *(u16 *)(iVar2 + 0x18) = uVar1;
    if ((s32)((unsigned int)uVar1 << 0x10) < 0) {
        *(u16 *)(iVar2 + 0x18) = 0;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
    *(u16 *)(iVar2 + 0x12) = (*(u16 *)(iVar2 + 0x12) + 0x22) & 0xfff;

    ((void (*)(s32, u8 *, u8 *, s32))func_8016BFA8)(param_1, p1, p2, iVar2 + 0x18);
}
