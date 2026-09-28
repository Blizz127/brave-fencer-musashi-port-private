/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801407F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 *D_8017FC60;
extern u8 *D_8017FC64;
extern u8 *D_8017FC68;
extern u8 *D_8017FC6C;
extern u8 *D_8017FC70;
extern u16 *D_8017FC74[];
extern u16 *D_8017FC7C[];
extern u16 *D_8017FC9C[];
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);

void func_801407F4(void)
{
    u8 *puVar1;
    s32 iVar2;
    u16 *puVar3;

    puVar1 = D_8017FC60;
    iVar2 = func_80028D58();
    puVar3 = D_8017FC74[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;

    puVar1 = D_8017FC64;
    iVar2 = func_80028DE0();
    puVar3 = D_8017FC74[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;

    iVar2 = func_80028FBC();
    *(s16 *)(D_8017FC68 + 0x18) = *D_8017FC7C[iVar2];
    iVar2 = func_80029000();
    *(s16 *)(D_8017FC6C + 0x18) = *D_8017FC7C[iVar2];

    puVar1 = D_8017FC70;
    iVar2 = func_80028D9C();
    puVar3 = D_8017FC9C[iVar2];
    *(s16 *)(puVar1 + 0x12) = *puVar3++;
    *(s16 *)(puVar1 + 0x14) = *puVar3++;
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    *(s16 *)(puVar1 + 0x1c) = *puVar3++;
}
