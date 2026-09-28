/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCD04 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCD04(void *a0) {
    extern void func_80148038(s32 a0, s32 a1);
    extern void func_80147460(s32 a0);
    extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_801473EC(s32 *a0);
    extern void func_8014ED28(s32);
    extern void func_80146D90(s32 a0);
    extern void func_80161450(void *a0);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80146CA0(void *a0);
    extern s32 func_801725A4(u8 *a0);
    s32 s1;

    func_80148038((s32)a0, 0x1A000);
    func_80147460((s32)a0);
    func_80147AD4((s32)a0, 0, 0, 0);
    func_801473EC((s32 *)a0);
    if (((int (*)(int))func_8014ED28)((s32)a0) != 0) {
        func_80146D90((s32)a0);
    }
    s1 = ((int (*)(int))func_80161450)(a0);
    if ((s1 & 5) != 0) {
        func_800CCE24(a0);
        func_80146E90((s32 *)a0, 0x10);
        func_80146CA0(a0);
    }
    if (s1 == 0) {
        func_801725A4((u8 *)a0);
        func_800CCEAC(a0);
    }
}
