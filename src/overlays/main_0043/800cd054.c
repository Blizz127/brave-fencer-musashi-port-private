/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD054 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 arg0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 a0);
s32 func_800CD258(void *a0, void *a1);
void func_800CD27C(s32 a0);
void func_800CD31C(s32 arg0);
typedef struct { char c[4]; } S4_800CD054;

void func_800CD054(void *a0) {
    extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                              s32 a4, s32 a5, s32 a6, s32 a7);
    extern void func_80147324(s32 a0);
    extern s32 func_80012FC8(s32 a0, s32 a1, s32 a2, s32 a3);
    extern s32 func_80146E98(s32 a0);
    extern void func_80146CA0(void *a0);
    extern u8 D_800CD704[];
    u8 *dp;
    s32 s1;
    s32 w;
    s32 v0;
    s32 v1;

    s1 = *(s32 *)((s32)a0 + 0x20);
    dp = D_800CD704;
    func_800CD258(a0, dp);
    func_800CD27C((s32)a0);
    if ((*(u32 *)((s32)a0 + 0x1C) & 7) == 0) {
        func_801466F0(6, (s32)a0, 0, 0, 0, *(s16 *)((s32)a0 + 0x62), 0, 1);
        w = *(u16 *)((s32)a0 + 0x62) + 1;
        *(u16 *)((s32)a0 + 0x62) = w;
        if ((s16)w >= 8) {
            *(u16 *)((s32)a0 + 0x62) = 0;
        }
        func_80147324(0x47E);
    }
    v0 = func_80012FC8(*(s16 *)(s1 + 0x1A), 0x5000, 0xA, 1);
    v1 = *(u16 *)(s1 + 0x1A) + v0;
    *(u16 *)(s1 + 0x1A) = v1;
    *(u16 *)(s1 + 0x18) = v1;
    v1 = *(u16 *)((s32)a0 + 0x60);
    v1 += 0x20;
    *(u16 *)((s32)a0 + 0x60) = v1;
    v0 = *(u16 *)(s1 + 0x1C) + v1;
    *(u16 *)(s1 + 0x1C) = v0;
    if ((s16)v0 >= 0x1000) {
        *(u16 *)(s1 + 0x1C) = 0x1000;
    }
    *(u16 *)(s1 + 0x1E) = *(u16 *)(s1 + 0x1C) | 0x4000;
    if (*(s16 *)(s1 + 0x1C) == 0x1000) {
        *(u16 *)(s1 + 0x1C) = 0;
        *(u16 *)((s32)a0 + 0x60) = 0;
        *(S4_800CD054 *)(dp + 4) = *(S4_800CD054 *)(dp + 0xC);
    }
    v0 = func_80146E98((s32)a0);
    if (v0 != 0) {
        func_80146CA0(a0);
    } else {
        func_800CD31C((s32)a0);
    }
}
