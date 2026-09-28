/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4EC - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CB4EC(s32 a0) {
    extern s32 func_80163408(s32 a1, s32 a2, s32 a3, s32 a4);
    extern void func_80163328();
    extern s32 func_801632F0();
    extern void func_80013E94(void *a1, void *a2);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern s16 D_80126B18[];
    extern s16 D_80126B1A[];
    extern s16 D_80126B1C[];
    extern s32 D_80114EB0;

    s32 sp20;
    s32 ret;

    func_80163408(a0, 0x28, 0, 0x1000);
    func_80163328(a0);
    if (func_801632F0(a0) == 0) {
        ret = 0;
    } else {
        func_80013E94(&D_80114EB0, &sp20);
        func_80146A6C(0xB, a0, D_80126B18[0], D_80126B1A[0], D_80126B1C[0], sp20, 0);
        ret = 1;
    }
    return ret;
}
