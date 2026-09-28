/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCDB0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CCE68(void);
extern void func_800CCF58();
extern void func_800CCE88(s32);
extern void func_800CCE68();
extern s32 func_800CCF30(void *a0);
extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800CCE88(s32 a0);

void func_800CCDB0(s32 param_1) {
    s32 s2 = *(s32 *)(param_1 + 0x4C);
    s32 s1 = *(s32 *)(param_1 + 0x20);
    s32 a1val;
    s32 v0;

    if (*(u16 *)(s2 + 0x1C8) & 0x10) {
        a1val = 0x1400;
    } else {
        a1val = 0x1000;
    }
    v0 = func_80012F74(*(s16 *)(s1 + 0x18), a1val, 0xA, 1);
    *(s16 *)(s1 + 0x18) = v0;
    func_800CCF58(s1, *(s16 *)(s1 + 0x18));
    if (func_800CCF30((void *)param_1) != 0) {
        return;
    }
    if (*(s16 *)(s2 + 0x1C8) == 0) {
        ((void (*)(s32))func_800CCE68)(param_1);
    } else {
        *(s16 *)(s2 + 0x1C8) -= 1;
        func_800CCE88(param_1);
    }
}
