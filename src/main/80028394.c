/* Main-exec range [80028394,80028428) from the SLUS executable.
 * SHA256(span)=15947463237df0902dbd6339b48bcd788ef9f39291f4c49a457946d900b550d4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80028394 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800A5E88;
extern s32 D_800A5E8C;
extern s32 D_800A5E90;
extern void func_80028620(s32, void *);

void func_80028394(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 offset;

    a0 &= 0xFFFF;
    if ((u16)a0 >= 3) {
        return;
    }

    offset = a0 << 4;

    *(s32 *)((s32)&D_800A5E88 + offset) += a1;
    *(s32 *)((s32)&D_800A5E8C + offset) += a2;
    *(s32 *)((s32)&D_800A5E90 + offset) += a3;

    func_80028620(a0, (void *)((s32)&D_800A5E88 + offset));
}
