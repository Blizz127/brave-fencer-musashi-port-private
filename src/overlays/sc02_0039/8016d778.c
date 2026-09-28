/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D778 - byte-exact against retail at -O2 (tools/register_match.py). */
#define main func_80010178
extern s32 D_80126B9C;
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_800D20C0(void *a0, void *a1, s32 a2);

void func_8016D778(s32 a0) {
    s32 s0 = a0;
    s32 p;
    s16 sp[6];
    if (*(s16 *)(s0 + 0x28) == *(s16 *)(*(s32 *)(s0 + 0x30) + 0x36)) {
        if ((D_80126B9C & 0x20) != 0) {
            goto main;
        }
    }
    ((void (*)(s32))func_80146C3C)(s0);
    return;
main:
    p = *(s32 *)(s0 + 0x20);
    *(u16 *)(p + 0x18) = *(u16 *)(p + 0x18) ^ 0x400;
    *(u16 *)(p + 0x1A) = *(u16 *)(p + 0x1A) ^ 0x200;
    sp[0] = *(u16 *)(s0 + 0x12);
    sp[1] = *(u16 *)(s0 + 0x16);
    sp[2] = *(u16 *)(s0 + 0x1A);
    func_800D20C0(&sp[0], &sp[4], 6);
    *(u16 *)(s0 + 6) = sp[0];
    *(u16 *)(s0 + 0xA) = sp[1];
    *(u16 *)(s0 + 0xE) = sp[2];
}
