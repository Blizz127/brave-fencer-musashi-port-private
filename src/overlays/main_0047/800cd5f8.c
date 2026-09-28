/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD5F8 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CD314(void *arg0);

void func_800CD5F8(void *arg0) {
    extern void func_801465C0(void);
    extern void func_8001CD50(s32 a0, s32 a1);
    extern void func_800CD314(void *a0);
    extern void func_80146C3C(void);
    extern u8 D_800CD7A4;
    extern u8 D_800CD7A5;
    extern u8 D_800CD7A6;
    extern u8 D_800CD7A8;
    extern u8 D_800CD7A9;
    extern u8 D_800CD7AA;

    s32 s1;
    s32 s0;

    s1 = ((s32 (*)(void))func_801465C0)();
    if (s1 != 0) {
        s0 = (s32)&D_800CD7A4;
        func_8001CD50(s1, s0);
        *(s32 *)((s32)arg0 + 0x20) = s1;
        *(s32 *)(s1 + 0x34) = (s32)arg0 + 0x38;
        *(s16 *)(s1 + 0x1E) = -0x7400;
        *(s32 *)(s1 + 4) |= 0x50000000;
        D_800CD7A5 = 0;
        *(u8 *)s0 = 0;
        D_800CD7A9 = 0x40;
        D_800CD7A8 = 0x40;
        D_800CD7A6 = 0;
        D_800CD7AA = 0x50;
        func_800CD314(arg0);
        *(u16 *)((s32)arg0 + 2) = *(u16 *)((s32)arg0 + 2) + 1;
    } else {
        ((void (*)(void *))func_80146C3C)(arg0);
    }
}
