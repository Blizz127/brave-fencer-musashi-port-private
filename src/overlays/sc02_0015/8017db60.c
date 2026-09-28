/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DB60 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern u8 *func_801290DC(s32 a0, u8 *a1);
extern void func_8017DC24(s32);
extern void func_8012931C(void *a0, s32 a1);
extern s32 D_80181D90;

void func_8017DB60(void *a0) {
    register s8 *s0 __asm__("$16");
    s32 t;
    u8 *p;
    s32 x;

    s0 = (s8 *)a0;
    ((void (*)(void))func_8017DC24)();
    *(s32 *)(s0 + 0x10) = *(volatile s32 *)(s0 + 0x10);
    t = *(volatile s32 *)(s0 + 0x18);
    *(s32 *)(s0 + 0x18) = t;
    *(s32 *)(s0 + 0x14) = *(s32 *)(s0 + 0x14) + 0xC000;
    func_8012931C(s0, t);
    if (*(s16 *)(s0 + 0x2E) < *(s16 *)(s0 + 0xA)) {
        *(s16 *)(s0 + 0xA) = *(s16 *)(s0 + 0x2E);
        func_80015978((s32)s0 + 4, &x);
        p = func_801290DC(0x28, (u8 *)&x);
        if (p != 0) {
            *(u32 *)(p + 0x2C) = D_80181D90++ & 7;
        }
        func_8002D4C8(0x572, 0);
        func_801292C8((u8 *)s0);
    }
}
