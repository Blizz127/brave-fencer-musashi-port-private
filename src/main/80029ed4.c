/* Main-exec range [80029ED4,80029FD4) from the SLUS executable.
 * SHA256(span)=3c28d8f5f2e8afbaafdfb13f9e43efbce4baec1a25a7c02da4416b34c395dfb2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80029ED4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_80029504(void);
extern s32 D_80078F04;
extern s32 D_80078F08;
extern s32 D_80078F0C;
extern s32 func_8002A2D4(s32);

void func_80029ED4(s32 arg0) {
    s32 v0;

    if (func_80029504() < 10) {
        return;
    }

    D_80078F04 += arg0;
    if ((u32)D_80078F04 < 0x66) {
        return;
    }
    D_80078F04 = (u32)D_80078F04 % 102u;

    D_80078F08 += 1;
    if ((u32)D_80078F08 > 9999999u) {
        D_80078F08 = 9999999;
    }

    v0 = D_80078F08 - D_80078F0C;
    if (v0 < 10) {
        return;
    }
    D_80078F0C = D_80078F08;
    func_8002A2D4(v0 / 10);
}
