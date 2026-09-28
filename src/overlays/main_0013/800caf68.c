/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161208();
extern void func_800CB05C(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80155FD4(s32 a0, s32 a1);

void func_800CAF68(s32 a0) {
    *(u32 *)(a0 + 0x44) |= 2;
    if (func_80161208() != 0) {
        return;
    }
    if (*(u16 *)(a0 + 0xB8) & 0x2000) {
        *(u8 *)(a0 + 0xBF) += 1;
    }
    if (*(u8 *)(a0 + 0xBF) != 0) {
        func_800CB05C(a0, *(u8 *)(a0 + 0xBF));
    }
    if (*(u16 *)(a0 + 0xB8) == 0x8000) {
        func_801599A4((void *)a0);
        func_80159B3C((void *)a0);
        return;
    }
    func_80155FD4(a0, *(u8 *)(a0 + 0x1AA));
}
