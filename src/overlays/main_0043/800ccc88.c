/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCC88 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCC88(void *a0) {
    extern void func_8014ED28(s32);
    extern void func_80146D90(s32);
    extern void func_8016151C(void *);
    extern s32 func_801725A4(u8 *);
    extern void func_80154274(s32 *, s32);
    extern void func_80146CA0(void *);
    extern s16 D_800D5404[];

    if (((int (*)(int))func_8014ED28)((s32)a0) != 0) {
        func_80146D90((s32)a0);
    }
    func_8016151C(a0);
    func_801725A4((u8 *)a0);
    if (*(u16 *)((char *)a0 + 0xB8) & 0x8000) {
        func_80154274((s32 *)a0, (s32)&D_800D5404);
        func_80146CA0(a0);
    }
    func_800CCEAC(a0);
}
