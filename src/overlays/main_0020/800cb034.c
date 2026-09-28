/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB034 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S;
extern void func_801599A4(void *a0);
extern s32 func_800CB17C(struct S *a0);

void func_800CB034(void *a0) {
    extern u16 func_80148800(s32 *a0);
    extern s32 func_80165A20(s32 a0);
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    extern void func_80154274(s32 *a0, s32 a1);
    extern s32 func_80148AFC(void *a0);
    extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_80147A84(s32 a0);
    extern void func_801473EC(s32 *a0);
    extern void func_80148038(s32 a0, s32 a1);
    extern void func_80147460(s32 a0);
    extern void func_8016151C(void *a0);
    extern s32 func_801615C4(void *a0, s32 a1);
    extern s32 D_80078EC8;
    extern s32 D_800CB234[];

    s32 s0 = (s32)a0;

    if ((func_80148800((s32 *)a0) & 0x20) || D_80078EC8 == 0) {
        func_80165A20(s0);
        func_801599A4((void *)s0);
        func_80159B3C((void *)s0);
        return;
    }
    if (*(u16 *)((s32)s0 + 0xB8) & 0x8000) {
        func_80154274((s32 *)s0, (s32)&D_800CB234);
    }
    if (func_80148AFC((void *)s0) & 0xFF) {
        func_80146DE8((s32 *)s0, 0, 0, -0x80000);
    } else {
        func_80146DE8((s32 *)s0, 0, 0, 0);
    }
    func_80147A84(s0);
    func_801473EC((s32 *)s0);
    func_80148038(s0, 0x30000);
    func_80147460(s0);
    if (((s32 (*)(void *))func_8016151C)((void *)s0) == 0) {
        return;
    }
    *(u16 *)((s32)s0 + 0xA) = *(u16 *)((s32)s0 + 0xA) + 8;
    func_801615C4((void *)s0, 0);
    func_800CB17C((struct S *)s0);
}
