/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCC54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_800CD684[])(void);
extern s16 D_800CE050;
extern s32 func_80012ABC(s32, s32, s32);
extern void func_8014ACC0(s32, s32);
extern s32 func_80161A00(s32 a0);
extern void func_80147364(s32 a, s32 b);
extern void func_800CCE60();

void func_800CCC54(s32 param_1)
{
    s32 iVar1;
    iVar1 = *(s32 *)(param_1 + 0x4C);
    D_800CD684[*(u16 *)(param_1 + 2)]();
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) &= 0x7FFFFFFF;
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) |= *(s32 *)(*(s32 *)(iVar1 + 0x20) + 4) & 0x80000000;
    *(u16 *)(param_1 + 0x60) = 0;
    D_800CE050 = func_80012ABC(D_800CE050, *(s16 *)(*(s32 *)(iVar1 + 0x20) + 0x12), 10);
    func_8014ACC0(iVar1, 1);
    if (func_80161A00(iVar1) == 0) {
        func_80147364(0x4, 0x8E0);
        ((void (*)(s32))func_800CCE60)(param_1);
    }
}
