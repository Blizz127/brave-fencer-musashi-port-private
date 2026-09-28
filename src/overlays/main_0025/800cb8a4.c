/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB8A4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB8A4(void *a0) {
    extern void func_80146578(void);
    extern void func_8001CEC0(s32 a0, void *a1);
    extern void func_8001CB00(s32 a0, void *a1, s32 a2, s32 a3);
    extern void func_800CBB50(void *a0);
    extern u8 D_800CBECC[];
    extern u8 D_800CBF20[];

    s32 s0;
    void *s1;

    s1 = a0;
    *(s32 *)((s32)s1 + 0x20) = 0;
    *(s32 *)((s32)s1 + 0x4C) = 0;
    s0 = ((s32 (*)(void))func_80146578)();
    if (s0) {
        *(s32 *)((s32)s1 + 0x20) = s0;
        func_8001CEC0(s0, D_800CBECC);
        *(u16 *)(s0 + 0x2C) = 1;
        *(s32 *)(s0 + 4) |= 0x80000000;
        *(s16 *)((s32)s1 + 6) = -0x28;
        *(s16 *)((s32)s1 + 0xA) = -0x40;
        s0 = ((s32 (*)(void))func_80146578)();
        if (s0) {
            *(s32 *)((s32)s1 + 0x10) = s0;
            func_8001CB00(s0, D_800CBF20, 0x1A0, 0x170);
            func_800CBB50(s0);
            *(u16 *)(s0 + 0x18) = 0;
            func_80146E90(s1, 6);
            func_80146CA0(s1);
        }
    }
}
