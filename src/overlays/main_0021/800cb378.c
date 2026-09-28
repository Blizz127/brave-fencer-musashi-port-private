/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB378 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB378(s32 arg0) {

    extern u8 D_80078EC1;
    extern void func_80146C3C();
    extern void func_801465C0(void);
    extern void func_8001CD50(s32 a0, s32 a1);
    extern void func_800233CC(void *a0, u16 a1);
    extern u8 D_800CB558;
    extern u8 D_800CB559;
    extern u8 D_800CB55A;
    extern u8 D_800CB55C;
    extern u8 D_800CB55D;
    extern u8 D_800CB55E;

    s32 s0;
    u8 *v1;
    u8 *a0p;
    s16 v0;
    register s32 ten __asm__("$3");

    if (D_80078EC1 != 2) {
        func_80146C3C(arg0);
        return;
    }
    if ((*(u32 *)(arg0 + 0x2C) & 0x8000) == 0) {
        v1 = &D_800CB559;
        a0p = v1 - 1;
        D_800CB55A = 0xA0;
        v1[0] = 0xA0;
        D_800CB55E = 0;
        D_800CB55D = 0;
        D_800CB55C = 0;
        a0p[0] = 0;
        func_800233CC(a0p, 0x60);
        v0 = 3;
    } else {
        s0 = ((s32 (*)(void))func_801465C0)();
        if (s0 == 0) {
            return;
        }
        func_8001CD50(s0, (s32)&D_800CB558);
        *(s32 *)(s0 + 0x34) = arg0 + 0x38;
        *(s16 *)(s0 + 0x1A) = 0;
        *(s16 *)(s0 + 0x18) = 0;
        *(u32 *)(s0 + 4) = *(u32 *)(s0 + 4) | 0x50000000;
        ten = 0x10;
        v0 = *(u16 *)(arg0 + 2) + 1;
        *(s32 *)(arg0 + 0x20) = s0;
        *(s32 *)(arg0 + 0x1C) = ten;
    }
    *(s16 *)(arg0 + 2) = v0;
}
