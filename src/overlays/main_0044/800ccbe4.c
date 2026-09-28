/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCBE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_800CE1F4[])(s32);
extern void func_800CCE68(void);
extern s32 func_801619D0(s32 a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 a0);

void func_800CCBE4(s32 param_1) {
    s32 iVar1;
    iVar1 = *(s32 *)(param_1 + 0x4C);
    D_800CE1F4[*(u16 *)(param_1 + 2)](param_1);
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) &= 0x7FFFFFFF;
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) |= *(s32 *)(*(s32 *)(iVar1 + 0x20) + 4) & 0x80000000;
    if (func_801619D0(iVar1) == 0) {
        ((void (*)(s32))func_800CCE68)(param_1);
        func_80146994(0x3A, iVar1, 0, 0);
        func_80147324(0xA13);
    }
}
