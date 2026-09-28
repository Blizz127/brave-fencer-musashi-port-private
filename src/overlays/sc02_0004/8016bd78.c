/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BD78 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_8019565C;
extern M2C_UNK D_80195660;

s32 func_8016BD78(s32 param_1)
{
    extern void func_8016BF50(void);
    extern u8 D_8019565D;
    extern u8 D_8019565E;
    extern u8 D_80195661;
    extern u8 D_80195662;

    s32 iVar2;
    u16 uVar1;
    u8 *p1;
    u8 *p2;

    iVar2 = *(s32 *)(param_1 + 0x20);
    func_8016BF50();

    p1 = &(*(u8 *)&D_8019565C);
    if (*p1 != 0) *p1 -= 4;
    if (D_8019565D != 0) D_8019565D -= 4;
    if (D_8019565E != 0) D_8019565E -= 4;
    p2 = &(*(u8 *)&D_80195660);
    if (*p2 != 0) *p2 -= 4;
    if (D_80195661 != 0) D_80195661 -= 4;
    if (D_80195662 != 0) D_80195662 -= 4;

    uVar1 = *(u16 *)(iVar2 + 0x18) - 0x80;
    *(u16 *)(iVar2 + 0x18) = uVar1;
    if ((s32)((unsigned int)uVar1 << 0x10) < 0) {
        *(u16 *)(iVar2 + 0x18) = 0;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
    *(u16 *)(iVar2 + 0x12) = (*(u16 *)(iVar2 + 0x12) + 0x22) & 0xfff;

    ((void (*)(s32, u8 *, u8 *, s32))func_8016BFA8)(param_1, p1, p2, iVar2 + 0x18);
}
