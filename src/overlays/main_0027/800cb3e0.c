/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_800CB82C(s32 a0, s32 a1);
extern s32 func_80146E98(s32 a0);
extern void func_80146D90(s32 a0);

void func_800CB3E0(s32 a0) {
    u8 *s0;
    u16 w;

    s0 = *(u8 **)(a0 + 0x20);
    func_800CB82C(a0, *(s32 *)(a0 + 0x58));

    *(u16 *)(a0 + 0xA) -= 1;

    w = *(u16 *)(s0 + 0x18);
    w += 0x100;
    *(u16 *)(s0 + 0x18) = w;
    if ((s16)w >= 0x1CCD) {
        *(u16 *)(s0 + 0x18) = 0x1CCC;
    }

    w = *(u16 *)(s0 + 0x1A);
    w += 0x100;
    *(u16 *)(s0 + 0x1A) = w;
    if ((s16)w >= 0x1CCD) {
        *(u16 *)(s0 + 0x1A) = 0x1CCC;
    }

    if (func_80146E98(a0) != 0) {
        *(u16 *)(s0 + 0x18) = 0x1CCC;
        *(u16 *)(s0 + 0x1A) = 0x1CCC;
        func_80146D90(a0);
        func_80146CA0((void *)a0);
    }
}
