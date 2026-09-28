/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80161208();
extern u16 func_801487F4(s32 *a0);
extern u8 D_800CBB84[];
extern u8 D_800CBB64[];

void func_800CAF1C(s32 *a0) {
    if (func_80161208() == 0) {
        if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
            if (func_801487F4(a0) & 0x20) {
                func_80154274(a0, (s32)D_800CBB84);
                *(u8 *)((u8 *)a0 + 0x197) += 1;
            } else {
                func_80154274(a0, (s32)D_800CBB64);
                *(u8 *)((u8 *)a0 + 0x197) += 2;
            }
        }
    }
}
