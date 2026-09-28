/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FE78 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801477E8(s32 *a0, s32 a1);
extern s32 func_80171990(u8 *a0);
extern u16 D_8011F73E;

s32 func_8016FE78(s32 *a0) {
    *(u16 *)((s32)a0 + 0xAA) |= 0x40;
    if (D_8011F73E != 0) {
        func_801477E8(a0, D_8011F73E << 16);
    }
    return func_80171990((u8 *)a0);
}
