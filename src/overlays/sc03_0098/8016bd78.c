/* Overlay range [8016BD78,8016BEA0) from MAIN.CD member 0012.
 * SHA256(span)=f2c05d6504e2619bc940c55136cd2afb70296a36a3e33ce730fdce432d524fd3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BD78 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern M2C_UNK D_801C48CC;
extern M2C_UNK D_801C48D0;
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8016BF50(s32);

s32 func_8016BD78(s32 param_1)
{

    extern M2C_UNK D_801C48CC;
    extern M2C_UNK D_801C48D0;
    extern u8 D_801C48CD;
    extern u8 D_801C48CE;
    extern u8 D_801C48D1;
    extern u8 D_801C48D2;

    s32 iVar2;
    u16 uVar1;
    u8 *p1;
    u8 *p2;

    iVar2 = *(s32 *)(param_1 + 0x20);
    ((void(*)())func_8016BF50)();

    p1 = &(*(u8 *)&D_801C48CC);
    if (*p1 != 0) *p1 -= 4;
    if (D_801C48CD != 0) D_801C48CD -= 4;
    if (D_801C48CE != 0) D_801C48CE -= 4;
    p2 = &(*(u8 *)&D_801C48D0);
    if (*p2 != 0) *p2 -= 4;
    if (D_801C48D1 != 0) D_801C48D1 -= 4;
    if (D_801C48D2 != 0) D_801C48D2 -= 4;

    uVar1 = *(u16 *)(iVar2 + 0x18) - 0x80;
    *(u16 *)(iVar2 + 0x18) = uVar1;
    if ((s32)((unsigned int)uVar1 << 0x10) < 0) {
        *(u16 *)(iVar2 + 0x18) = 0;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
    *(u16 *)(iVar2 + 0x12) = (*(u16 *)(iVar2 + 0x12) + 0x22) & 0xfff;

    ((void (*)(s32, u8 *, u8 *, s32))func_8016BFA8)(param_1, p1, p2, iVar2 + 0x18);
}
