/* Main-exec range [80028304,80028394) from the SLUS executable.
 * SHA256(span)=6aa6f70ca2445b436504c133f471a504492b7a2e46a68227ce05d4ccd514f424.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80028304 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800A5E88;
extern s32 D_800A5E8C;
extern s32 D_800A5E90;
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;
extern void func_80028620(s32 a0, void *a1);

void func_80028304(s32 a0, s32 a1, s32 a2, s32 a3, u8 a4, u8 a5, u8 a6) {
    s32 offset;

    a0 &= 0xFFFF;
    if ((u16)a0 >= 3) {
        return;
    }

    offset = a0 << 4;

    *(s32 *)((s32)&D_800A5E88 + offset) = a1;
    *(s32 *)((s32)&D_800A5E8C + offset) = a2;
    *(s32 *)((s32)&D_800A5E90 + offset) = a3;
    *(u8 *)((s32)&D_800A5E94 + offset) = a4;
    *(u8 *)((s32)&D_800A5E95 + offset) = a5;
    *(u8 *)((s32)&D_800A5E96 + offset) = a6;

    func_80028620(a0, (void *)((s32)&D_800A5E88 + offset));
}
