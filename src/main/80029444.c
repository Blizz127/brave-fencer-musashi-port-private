/* Main-exec range [80029444,80029504) from the SLUS executable.
 * SHA256(span)=d87446017e116b46ea20dbbde71435298790b685750b7db408222e40b5d3f0e8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80029444 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_80078E7C __asm__("D_80078E7C");
extern u8 D_80078E7C_1 __asm__("D_80078E7C+1");
extern u8 D_80078E7C_2 __asm__("D_80078E7C+2");
extern u8 D_80078E7C_3 __asm__("D_80078E7C+3");
extern u32 D_80078E7C_w __asm__("D_80078E7C");

void func_80029444(void) {
    if ((u8)(++D_80078E7C) < 30) {
        return;
    }
    D_80078E7C = 0;
    if ((u8)(++D_80078E7C_1) < 60) {
        return;
    }
    D_80078E7C_1 = 0;
    if ((u8)(++D_80078E7C_2) < 60) {
        return;
    }
    D_80078E7C_2 = 0;
    if ((u8)(++D_80078E7C_3) < 100) {
        return;
    }
    D_80078E7C_w = 0x633B3B00;
}
