/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEB0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801657A0();
extern s32 func_80165910();
extern void func_80147324(s32 arg0);
extern void func_8014B944(s32 a0, s32 a1, s32 a2);
extern void func_801655E4(s32 a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800CAEB0(void *a0) {
    func_801657A0(a0);
    if (func_80165910((s32)a0) == 0) {
        func_80147324(0x7A3);
        func_8014B944((s32)a0, 0x100000, 1);
        func_801655E4((s32)a0);
    }
    func_80146A6C(0x21, a0, 0, 0, 0, 0, 0);
    *(u8 *)((s32)a0 + 0x197) += 1;
}
