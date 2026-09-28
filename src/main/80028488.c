/* Main-exec range [80028488,8002850C) from the SLUS executable.
 * SHA256(span)=8751db49e198c44176eabc2fc6f331475d627fdbc86e66e6e86f500ddaf09f37.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80028488 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800A5E88;
extern s32 D_800A5E8C;
extern s32 D_800A5E90;
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;
extern void func_80028620(s32 a0, void *a1);

void func_80028488(s32 slot) {
    s32 offset;

    slot &= 0xFFFF;
    if ((u16)slot >= 3) {
        return;
    }
    offset = slot << 4;
    *(s32 *)((s32)&D_800A5E90 + offset) = 100;
    *(s32 *)((s32)&D_800A5E88 + offset) = 0;
    *(s32 *)((s32)&D_800A5E8C + offset) = 0;
    *(u8 *)((s32)&D_800A5E94 + offset) = 0;
    *(u8 *)((s32)&D_800A5E95 + offset) = 0;
    *(u8 *)((s32)&D_800A5E96 + offset) = 0;
    func_80028620(slot, (void *)((s32)&D_800A5E88 + offset));
}
