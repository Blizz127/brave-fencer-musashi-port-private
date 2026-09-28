/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB23C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB6CC(void*);

void func_800CB23C(void *a0) {
    extern u8 D_800CBE98[];
    extern void func_8014659C(void);
    extern void func_8001CA1C(void *a0, void *a1);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_80146E90(s32 *a0, s16 a1);
    extern void func_80146CA0(void *a0);
    extern void func_800CB758(void *a0);
    extern void func_800CB6CC(void *a0);

    s32 s1;
    s32 v0;

    s1 = *(s32 *)((s32)a0 + 0x4C);
    v0 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 != 0) {
        func_8001CA1C((void *)v0, D_800CBE98);
        func_80149374(s1, (s32)a0 + 4);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x10) = *(u16 *)(s1 + 0x100);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14) = *(u16 *)(s1 + 0x104);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = *(u16 *)(*(s32 *)(s1 + 0x20) + 0x12);
        func_80146DE8((s32 *)a0, 0, 0x80000, 0xFFF00000);
        func_80146E90((s32 *)a0, 0x60);
        func_800CB758(a0);
        func_80146CA0(a0);
    } else {
        func_800CB6CC(a0);
    }
}
