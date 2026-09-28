/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80156370 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
typedef struct { s32 a, b, c; } S801563EC;
extern S801563EC *func_801563EC(u16 idx);
extern s32 rand(void);

u16 func_80156370(u16 param_1) {
    u16 *puVar3;
    u16 uVar1;
    u16 uVar2;
    s32 iVar4;
    s32 iVar5;
    puVar3 = ((u16 * (*)(s32))func_801563EC)(param_1 & 0xFFFF);
    uVar1 = puVar3[0] & 0xfff;
    uVar2 = puVar3[1];
    iVar4 = rand();
    iVar5 = uVar2 + 1;
    return (u16)(uVar1 + iVar4 % iVar5);
}
