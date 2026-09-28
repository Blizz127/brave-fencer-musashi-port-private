/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAED8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;

void func_800CAED8(u8 *a0) {
    extern s32 D_8011F9D0;
    extern M2C_UNK D_800D57F4;
    extern void func_80154274(s32 *a0, s32 a1);
    extern void func_801655E4(void *a0);
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    s32 count = 0;
    s32 i;

    for (i = 0; i < 0x14; i++) {
        if (*(u16 *)((s32)&D_8011F9D0 + i * 0x68) == 0x25) {
            count++;
        }
    }

    if (count >= 6) {
        func_801599A4(a0);
        func_80159B3C(a0);
    } else {
        func_80154274((s32 *)a0, &D_800D57F4);
        func_801655E4(a0);
        *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
    }
}
