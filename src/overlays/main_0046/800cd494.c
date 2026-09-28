/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD494 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_800CDA14(s32 a0);

void func_800CD494(void *a0) {
    register s32 rv __asm__("$2");
    s32 s0;
    s32 s1;
    u16 v0;
    u16 v1;

    s0 = (s32)a0;
    s1 = *(s32 *)(s0 + 0x20);
    *(s32 *)(s0 + 0x44) |= 2;
    v0 = func_80148800((s32 *)a0);
    if (v0 & 0x90) {
        *(u16 *)(s0 + 0x240) = 0;
        func_80147324(0x8E4);
    }
    v0 = func_801487F4((s32 *)s0);
    if (v0 & 0x90) {
        func_800CDA14(s0);
        v0 = *(u16 *)(s0 + 0x246);
        v0 = v0 + 8;
        *(u16 *)(s0 + 0x246) = v0;
        if ((s16)v0 >= 0x201) {
            *(u16 *)(s0 + 0x246) = 0x200;
        }
        v0 = *(u16 *)(s0 + 0x240);
        v1 = *(u16 *)(s0 + 0x246);
        v0 = v0 + v1;
        *(u16 *)(s0 + 0x240) = v0;
        if ((s16)v0 >= 0x1000) {
            *(u16 *)(s0 + 0x240) = 0;
            func_80147324(0x8E4);
        }
    } else {
        v0 = *(u16 *)(s0 + 0x246);
        v0 = v0 - 0x20;
        *(u16 *)(s0 + 0x246) = v0;
        if ((s16)v0 <= 0) {
            *(u16 *)(s0 + 0x246) = 0;
        }
    }
    v0 = *(u16 *)(s0 + 0x244);
    v1 = *(u16 *)(s0 + 0x246);
    v0 = v0 + v1;
    v0 = v0 & 0xFFF;
    *(u16 *)(s0 + 0x244) = v0;
    *(u16 *)(s1 + 0x12) = v0;
    if (*(s16 *)(s0 + 0x246) == 0) {
        func_801599A4((void *)s0);
        func_80159B3C((void *)s0);
        rv = 1;
    } else {
        rv = 0;
    }
    __asm__ __volatile__("" : : "r"(rv));
}
