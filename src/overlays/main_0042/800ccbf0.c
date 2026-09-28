/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCBF0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078E78[];
extern void func_800CCD60(s32);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern s32 func_80155FB0(s32 a0, s32 a1);

void func_800CCBF0(u8 *a0) {
    volatile s32 dead[12];
    u8 *p = D_80078E78;
    s32 var = *(s32 *)(a0 + 0x23C);

    if (var == 0) {
        if (*(u16 *)(a0 + 0xB8) & 0x4000) {
            *(s32 *)(a0 + 0x23C) = 1;
            ((void (*)(void *))func_800CCD60)(a0);
        }
    } else {
        if (var >= 0) {
            if (var < 7) {
                *(s32 *)(a0 + 0x23C) = var + 1;
                ((void (*)(void *))func_800CCD60)(a0);
            }
        }
    }

    switch (*(s32 *)(a0 + 0x234)) {
    case 0:
        if (*(u16 *)(a0 + 0xB8) & 0x8000) {
            if (*(s16 *)(a0 + 0x246) < 0x1000) {
                *(u16 *)(a0 + 0x248) += 30;
                *(u16 *)(a0 + 0x246) += *(u16 *)(a0 + 0x248);
                *(u16 *)(a0 + 0x24A) = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
                *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
                    *(u16 *)(a0 + 0x244) + *(u16 *)(a0 + 0x246);
                func_80155FB0((s32)a0, (p[0x48] & 0x7F) - 1);
            } else {
                *(u16 *)(a0 + 0xB8) = 1;
                *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) = *(u16 *)(a0 + 0x244);
                *(s32 *)(a0 + 0x234) += 1;
            }
        }
        break;
    case 1:
        if (*(u16 *)(a0 + 0xB8) & 0x8000) {
            func_801599A4(a0);
            func_80159B3C(a0);
            return;
        }
        break;
    }
    func_80161208(a0);
}
