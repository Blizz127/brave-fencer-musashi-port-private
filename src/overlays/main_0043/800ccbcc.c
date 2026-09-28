/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCBCC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCBCC(s32 a0)
{
    extern void func_80148038(s32 a0, s32 a1);
    extern void func_80147460(s32 a0);
    extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_801473EC(s32 *a0);
    extern void func_8014ED28();
    extern void func_80146D90(s32 a0);
    extern void func_8016151C(void *a0);
    extern s32 func_801725A4(u8 *a0);
    extern void func_801477E8(s32 *a0, s32 a1);
    extern void func_80154274(s32 *a0, s32 a1);
    extern void func_80146CA0(void *a0);
    extern void func_800CCEAC(void *a0);
    extern u8 D_800D53C0[];

    func_80148038(a0, 0x1A000);
    func_80147460(a0);
    func_80147AD4(a0, 0, 0, 0);
    func_801473EC((s32 *)a0);
    {
        register s32 ret __asm__("$2");
        func_8014ED28(a0);
        __asm__ __volatile__("" : "=r"(ret));
        if (ret != 0) {
            func_80146D90(a0);
        }
    }
    func_8016151C((void *)a0);
    func_801725A4((u8 *)a0);
    if (*(s32 *)(a0 + 0x34) > 0) {
        func_801477E8((s32 *)a0, 0x40000);
        func_80154274((s32 *)a0, (s32)D_800D53C0);
        func_80146CA0((void *)a0);
    } else {
        func_800CCEAC((void *)a0);
    }
}
