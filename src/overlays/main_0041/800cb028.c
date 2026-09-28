/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB028 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB338(void);
extern void func_8014659C(void);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 D_800CBE04;
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);

void func_800CB028(s32 a0) {
    s32 s2;
    s32 s0;

    s2 = *(s32 *)(a0 + 0x4C);
    s0 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(a0 + 0x20) = s0;
    if (s0 != 0) {
        func_8001C214(s0, (s32)&D_800CBE04);
        *(u16 *)(s0 + 0x2C) = *(u16 *)(s0 + 0x2C) | 0x10;
        *(u16 *)(s0 + 0x1C) = 0x2000;
        *(u16 *)(s0 + 0x1A) = 0x2000;
        *(u16 *)(s0 + 0x18) = 0x2000;
        *(u16 *)(s0 + 0x12) = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x12);
        func_80149374(s2, a0 + 4);
        func_80146DE8((s32 *)a0, 0, 0, 0xFFE80000);
        func_80146E90((s32 *)a0, 0x3C);
        func_80146A6C(0x4F, (void *)a0, 0, 0, 0, 0, 0);
        func_80147324(0x8E5);
        func_80146CA0((void *)a0);
    } else {
        ((void (*)(s32))func_800CB338)(a0);
    }
}
