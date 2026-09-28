/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB038 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB3BC(void);

void func_800CB038(void *a0) {
    extern s32 D_800CBD74;
    extern void func_8014659C(void);
    extern void func_8001C214(s32 a0, s32 a1);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80147324(s32 a0);
    extern void func_80146CA0(void *a0);
    extern void func_800CB3BC(void);

    void *s2 = *(void **)((s32)a0 + 0x4C);
    s32 s1 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)((s32)a0 + 0x20) = s1;
    if (s1 != 0) {
        func_8001C214(s1, (s32)&D_800CBD74);
        *(u16 *)(s1 + 0x12) = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x12);
        func_80149374((s32)s2, (s32)a0 + 4);
        func_80146DE8((s32 *)a0, 0, -0xC0000, -0x100000);
        func_80146E90((s32 *)a0, 100);
        memcpy((void *)((s32)a0 + 0x58), (void *)(s1 + 0x10), 8);
        *(u16 *)((s32)a0 + 0x60) = 2;
        func_80147324(0x8F3);
        func_80146CA0(a0);
    } else {
        ((void (*)(s32))func_800CB3BC)(a0);
    }
}
