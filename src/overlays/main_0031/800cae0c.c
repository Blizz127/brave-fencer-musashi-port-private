/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAE0C(void) {
    extern void func_800CAE74();
    extern void func_800183E0(s32 a0);
    extern u8 D_800CC09C[];
    extern u8 D_800CBF3C[];
    extern u8 D_800CBF7C[];
    extern u8 D_800CC0DC[];
    extern u8 D_800CBF5C[];
    extern u8 D_800CBFA8[];
    extern u8 D_800CC05C[];

    func_800CAE74((void *)&D_800CC09C, (void *)&D_800CBF3C, (void *)&D_800CBF7C);
    func_800CAE74((void *)&D_800CC0DC, (void *)&D_800CBF5C, (void *)&D_800CBFA8);
    func_800183E0((s32)&D_800CC05C);
}
