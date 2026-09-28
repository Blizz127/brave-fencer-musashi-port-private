/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCF50 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCF50(void *a0) {

    extern void func_80146578(void);
    extern void func_8001CD50(s32 a0, s32 a1);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_800CD1F4(void *a0, void *a1);
    extern void func_800CD258(void *a0, void *a1);
    extern void func_800CD27C(s32 a0);
    extern void func_80146CA0(void *);
    extern void func_800CD1D4(void);
    extern u8 D_800CD704[];
    extern u8 D_800CD744[];

    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register s32 s2 __asm__("$18");
    register s32 s3 __asm__("$19");

    s1 = (s32)a0;
    s2 = *(s32 *)(s1 + 0x4C);
    s0 = (s32)((void *(*)(void))func_80146578)();
    s3 = (s32)&D_800CD704;
    *(s32 *)(s1 + 0x20) = s0;

    if (s0 != 0) {
        func_8001CD50(s0, s3);
        *(s32 *)(s0 + 0x34) = (s32)&D_800CD744;
        *(s32 *)(s0 + 4) |= 0x50000000;
        *(u16 *)(s0 + 0x1C) = 0;
        func_80149374(s2, s1 + 4);
        *(u16 *)(s0 + 0x10) = *(u16 *)(s2 + 0x100);
        *(u16 *)(s0 + 0x14) = *(u16 *)(s2 + 0x104);
        *(u16 *)(s0 + 0x12) = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x12);
        func_80146E90((s32 *)s1, 0x10);
        *(u16 *)(s1 + 0x60) = 0;
        *(u16 *)(s1 + 0x62) = 0;
        func_800CD1F4((void *)s1, (void *)s3);
        func_800CD258((void *)s1, (void *)s3);
        func_800CD27C(s1);
        func_80146CA0((void *)s1);
    } else {
        ((void (*)(void *))func_800CD1D4)((void *)s1);
    }
}
