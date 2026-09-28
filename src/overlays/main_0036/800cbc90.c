/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32);
extern s32 func_80146E98(s32 a0);
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_800CBD2C(s32 param_1);
extern void func_800CBEB0(s32 a0);
extern void func_800CBF3C();

void func_800CBC90(s32 arg0) {
    u16 *rec = *(u16 **)(arg0 + 0x20);
    rec[8] += 0x2D;
    rec[9] += 0x2D;
    rec[0xA] += 0x2D;
    *(s32 *)(arg0 + 0x14) += 0x4000;
    func_800CBD2C(arg0);
    func_800CBEB0(arg0);
    if (*(s32 *)(arg0 + 0x2C) == 0) {
        func_800CBF3C();
    }
    if (func_80146E98(arg0) != 0) {
        ((void (*)(s32))func_80146C3C)(arg0);
    }
}
