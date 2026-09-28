/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800183E0(s32 a0);

void func_800CAE0C(void) {
    extern s32 D_800CC57C;
    extern s32 D_800CC5BC;
    extern s32 D_800CB93C;

    func_800183E0((s32)&D_800CC57C);
    func_800183E0((s32)&D_800CC5BC);
    func_800183E0((s32)&D_800CB93C);
}
