/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD708 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800CE8D4;
extern void (*D_800CE080[])(void);
extern s32 func_80012ABC(s32 a0, s32 a1, s32 a2);
extern void func_8014ACC0(s32 a0, s32 a1);
extern s32 func_80161A30(s32 a0);
extern void func_800CD94C(void);

void func_800CD708(s32 param_1)
{
    s32 s0;
    s32 iVar1;
    s0 = *(s32 *)(param_1 + 0x4C);
    D_800CE080[*(u16 *)(param_1 + 2)]();

    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) &= 0x7FFFFFFF;
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) |= (*(s32 *)(*(s32 *)(s0 + 0x20) + 4)) & 0x80000000;

    *(s16 *)(param_1 + 0x60) = 0;

    iVar1 = *(s32 *)(s0 + 0x20);
    D_800CE8D4 = func_80012ABC(D_800CE8D4, *(s16 *)(iVar1 + 0x12), 0xA);

    func_8014ACC0(s0, 1);
    if (func_80161A30(s0) != 0) {
        return;
    }
    ((void (*)(s32))func_800CD94C)(param_1);
}
