/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801407F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);
extern u8 *D_8017ED34;
extern u8 *D_8017ED38;
extern u8 *D_8017ED3C;
extern u8 *D_8017ED40;
extern u8 *D_8017ED44;
extern u16 *D_8017ED48[];
extern u16 *D_8017ED50[];
extern u16 *D_8017ED70[];

void func_801407F4(void)
{
    u8 *puVar1;
    s32 iVar2;
    u16 *puVar3;

    puVar1 = D_8017ED34;
    iVar2 = func_80028D58();
    puVar3 = D_8017ED48[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;

    puVar1 = D_8017ED38;
    iVar2 = func_80028DE0();
    puVar3 = D_8017ED48[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;

    iVar2 = func_80028FBC();
    *(s16 *)(D_8017ED3C + 0x18) = *D_8017ED50[iVar2];
    iVar2 = func_80029000();
    *(s16 *)(D_8017ED40 + 0x18) = *D_8017ED50[iVar2];

    puVar1 = D_8017ED44;
    iVar2 = func_80028D9C();
    puVar3 = D_8017ED70[iVar2];
    *(s16 *)(puVar1 + 0x12) = *puVar3++;
    *(s16 *)(puVar1 + 0x14) = *puVar3++;
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    *(s16 *)(puVar1 + 0x1c) = *puVar3++;
}
